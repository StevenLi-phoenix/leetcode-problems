// @leetcode id=1218 questionId=1330 slug=longest-arithmetic-subsequence-of-given-difference lang=cpp site=leetcode.com title="Longest Arithmetic Subsequence of Given Difference"
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; // dp[v] = longest subsequence ending with value v
        int maxLen = 1;
        
        for (int x : arr) {
            int prev = x - difference;
            int len = 1;
            if (dp.count(prev)) {
                len = dp[prev] + 1;
            }
            dp[x] = max(dp[x], len); // handle duplicates - keep max
            maxLen = max(maxLen, dp[x]);
        }
        
        return maxLen;
    }
};
