// @leetcode id=873 questionId=905 slug=length-of-longest-fibonacci-subsequence lang=cpp site=leetcode.com title="Length of Longest Fibonacci Subsequence"
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) idx[arr[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int best = 0;

        for (int k = 0; k < n; k++) {
            for (int j = 0; j < k; j++) {
                int need = arr[k] - arr[j];
                if (need >= arr[j]) continue;
                auto it = idx.find(need);
                if (it == idx.end()) continue;
                int i = it->second;
                dp[j][k] = dp[i][j] + 1;
                best = max(best, dp[j][k]);
            }
        }
        return best;
    }
};
