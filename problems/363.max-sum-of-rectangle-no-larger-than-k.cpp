// @leetcode id=363 questionId=363 slug=max-sum-of-rectangle-no-larger-than-k lang=cpp site=leetcode.com title="Max Sum of Rectangle No Larger Than K"
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int best = INT_MIN;

        for (int left = 0; left < n; ++left) {
            vector<int> rowSum(m, 0);
            for (int right = left; right < n; ++right) {
                for (int r = 0; r < m; ++r) {
                    rowSum[r] += matrix[r][right];
                }

                // find max subarray sum of rowSum that is <= k
                set<int> prefixSums;
                prefixSums.insert(0);
                int curSum = 0;
                for (int r = 0; r < m; ++r) {
                    curSum += rowSum[r];
                    auto it = prefixSums.lower_bound(curSum - k);
                    if (it != prefixSums.end()) {
                        best = max(best, curSum - *it);
                    }
                    prefixSums.insert(curSum);
                }
            }
        }
        return best;
    }
};
