// @leetcode id=2573 questionId=2708 slug=find-the-string-with-lcp lang=cpp site=leetcode.com title="Find the String with LCP"
class Solution {
    public:
    string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    string word(n, 0);
    char c = 'a';
    for (int i = 0; i < n; i++) {
    if (word[i]) continue;
    if (c > 'z') return "";
    word[i] = c;
    for (int j = i + 1; j < n; j++) {
    if (lcp[i][j] > 0) {
    if (word[j] && word[j] != c) return "";
    word[j] = c;
    }
    }
    c++;
    }
    // verify
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
    if (word[i] == word[j]) dp[i][j] = dp[i+1][j+1] + 1;
    else dp[i][j] = 0;
    if (dp[i][j] != lcp[i][j]) return "";
    }
    }
    return word;
    }
    };
