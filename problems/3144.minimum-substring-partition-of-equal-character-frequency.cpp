// @leetcode id=3144 questionId=3403 slug=minimum-substring-partition-of-equal-character-frequency lang=cpp site=leetcode.com title="Minimum Substring Partition of Equal Character Frequency"
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int freq[26] = {0};
            int maxFreq = 0, distinctCount = 0, countAtMax = 0;
            for (int j = i - 1; j >= 0; --j) {
                int c = s[j] - 'a';
                if (freq[c] == 0) {
                    ++distinctCount;
                    freq[c] = 1;
                    if (maxFreq == 0) { maxFreq = 1; countAtMax = 1; }
                    else if (maxFreq == 1) ++countAtMax;
                } else {
                    int old = freq[c];
                    freq[c] = old + 1;
                    if (old == maxFreq) { maxFreq = old + 1; countAtMax = 1; }
                    else if (old + 1 == maxFreq) ++countAtMax;
                }
                if (countAtMax == distinctCount && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
