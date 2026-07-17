// @leetcode id=2035 questionId=2162 slug=partition-array-into-two-arrays-to-minimize-sum-difference lang=cpp site=leetcode.com title="Partition Array Into Two Arrays to Minimize Sum Difference"
class Solution {
public:
    void genSubsets(vector<int>& arr, vector<vector<long long>>& byCount) {
        int sz = arr.size();
        for (int mask = 0; mask < (1 << sz); mask++) {
            int cnt = __builtin_popcount(mask);
            long long sum = 0;
            for (int i = 0; i < sz; i++) if (mask & (1 << i)) sum += arr[i];
            byCount[cnt].push_back(sum);
        }
        for (auto& v : byCount) sort(v.begin(), v.end());
    }

    int minimumDifference(vector<int>& nums) {
        int total2n = nums.size();
        int n = total2n / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<long long>> leftByCount(n + 1), rightByCount(n + 1);
        genSubsets(left, leftByCount);
        genSubsets(right, rightByCount);

        long long total = 0;
        for (int x : nums) total += x;

        long long best = LLONG_MAX;

        for (int c = 0; c <= n; c++) {
            int rc = n - c;
            auto& rightArr = rightByCount[rc];
            for (long long ls : leftByCount[c]) {
                // want rightSum rs minimizing |total - 2*(ls+rs)|, i.e rs close to (total - 2*ls)/2.0
                double targetD = (total - 2.0 * ls) / 2.0;
                auto it = lower_bound(rightArr.begin(), rightArr.end(), (long long)ceil(targetD));

                if (it != rightArr.end()) {
                    long long diff = llabs(total - 2 * (ls + *it));
                    best = min(best, diff);
                }
                if (it != rightArr.begin()) {
                    long long rs = *prev(it);
                    long long diff = llabs(total - 2 * (ls + rs));
                    best = min(best, diff);
                }
            }
        }

        return (int)best;
    }
};
