// @leetcode id=3628 questionId=3948 slug=maximum-number-of-subsequences-after-one-inserting lang=cpp site=leetcode.com title="Maximum Number of Subsequences After One Inserting"
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        vector<long long> prefixL(n + 1, 0), prefixLC(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixL[i + 1] = prefixL[i] + (s[i] == 'L');
            prefixLC[i + 1] = prefixLC[i] + (s[i] == 'C' ? prefixL[i] : 0);
        }

        vector<long long> suffixT(n + 1, 0), suffixCT(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixT[i] = suffixT[i + 1] + (s[i] == 'T');
            suffixCT[i] = suffixCT[i + 1] + (s[i] == 'C' ? suffixT[i + 1] : 0);
        }

        long long base = 0;
        long long countL = 0, countLC = 0;
        for (char c : s) {
            if (c == 'L') ++countL;
            else if (c == 'C') countLC += countL;
            else if (c == 'T') base += countLC;
        }

        long long insertLGain = suffixCT[0];
        long long insertTGain = prefixLC[n];

        long long insertCGain = 0;
        for (int i = 0; i <= n; ++i) {
            insertCGain = max(insertCGain, prefixL[i] * suffixT[i]);
        }

        return base + max({insertLGain, insertTGain, insertCGain});
    }
};
