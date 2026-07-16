// @leetcode id=3424 questionId=3712 slug=minimum-cost-to-make-arrays-identical lang=cpp site=leetcode.com title="Minimum Cost to Make Arrays Identical"
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long withoutRearrange = 0;
        for (int i = 0; i < n; i++) {
            withoutRearrange += abs((long long)arr[i] - brr[i]);
        }

        vector<int> sortedArr = arr, sortedBrr = brr;
        sort(sortedArr.begin(), sortedArr.end());
        sort(sortedBrr.begin(), sortedBrr.end());
        long long withRearrange = k;
        for (int i = 0; i < n; i++) {
            withRearrange += abs((long long)sortedArr[i] - sortedBrr[i]);
        }

        return min(withoutRearrange, withRearrange);
    }
};
