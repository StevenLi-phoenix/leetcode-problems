// @leetcode id=131 questionId=131 slug=palindrome-partitioning lang=cpp site=leetcode.com title="Palindrome Partitioning"
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // Precompute palindrome table
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int i = 0; i + 1 < n; i++) dp[i][i+1] = (s[i] == s[i+1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            }
        }
        
        vector<vector<string>> result;
        vector<string> current;
        
        function<void(int)> backtrack = [&](int start) {
            if (start == n) {
                result.push_back(current);
                return;
            }
            for (int end = start; end < n; end++) {
                if (dp[start][end]) {
                    current.push_back(s.substr(start, end - start + 1));
                    backtrack(end + 1);
                    current.pop_back();
                }
            }
        };
        
        backtrack(0);
        return result;
    }
};
