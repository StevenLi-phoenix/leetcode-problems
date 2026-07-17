// @leetcode id=2223 questionId=2326 slug=sum-of-scores-of-built-strings lang=cpp site=leetcode.com title="Sum of Scores of Built Strings"
class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }

        long long answer = n;
        for (int i = 1; i < n; i++) answer += z[i];
        return answer;
    }
};
