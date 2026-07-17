// @leetcode id=3072 questionId=3350 slug=distribute-elements-into-two-arrays-ii lang=cpp site=leetcode.com title="Distribute Elements Into Two Arrays II"
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedVals = nums;
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int m = sortedVals.size();

        auto rankOf = [&](int v) {
            return lower_bound(sortedVals.begin(), sortedVals.end(), v) - sortedVals.begin() + 1;
        };

        vector<long long> bit1(m + 1, 0), bit2(m + 1, 0);
        auto update = [&](vector<long long>& bit, int pos, int delta) {
            for (; pos <= m; pos += pos & (-pos)) bit[pos] += delta;
        };
        auto query = [&](vector<long long>& bit, int pos) {
            long long res = 0;
            for (; pos > 0; pos -= pos & (-pos)) res += bit[pos];
            return res;
        };
        // greaterCount(arr, val) = count of elements > val = totalInArr - countLessEqual(val)

        vector<int> arr1, arr2;

        int r0 = rankOf(nums[0]);
        arr1.push_back(nums[0]);
        update(bit1, r0, 1);

        int r1 = rankOf(nums[1]);
        arr2.push_back(nums[1]);
        update(bit2, r1, 1);

        for (int i = 2; i < n; i++) {
            int r = rankOf(nums[i]);
            long long g1 = (long long)arr1.size() - query(bit1, r);
            long long g2 = (long long)arr2.size() - query(bit2, r);

            bool toArr1;
            if (g1 > g2) toArr1 = true;
            else if (g1 < g2) toArr1 = false;
            else {
                if (arr1.size() < arr2.size()) toArr1 = true;
                else if (arr1.size() > arr2.size()) toArr1 = false;
                else toArr1 = true;
            }

            if (toArr1) {
                arr1.push_back(nums[i]);
                update(bit1, r, 1);
            } else {
                arr2.push_back(nums[i]);
                update(bit2, r, 1);
            }
        }

        vector<int> result;
        result.reserve(n);
        for (int x : arr1) result.push_back(x);
        for (int x : arr2) result.push_back(x);

        return result;
    }
};
