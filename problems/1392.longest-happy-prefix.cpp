// @leetcode id=1392 questionId=1508 slug=longest-happy-prefix lang=cpp site=leetcode.com title="Longest Happy Prefix"
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> fail(n, 0);
        int k = 0;
        for (int i = 1; i < n; i++) {
            while (k > 0 && s[i] != s[k]) k = fail[k - 1];
            if (s[i] == s[k]) k++;
            fail[i] = k;
        }
        return s.substr(0, fail[n - 1]);
    }
};
