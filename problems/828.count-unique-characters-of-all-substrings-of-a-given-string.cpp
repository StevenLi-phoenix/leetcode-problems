// @leetcode id=828 questionId=855 slug=count-unique-characters-of-all-substrings-of-a-given-string lang=cpp site=leetcode.com title="Count Unique Characters of All Substrings of a Given String"
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> prev(n), next(n);
        int lastSeen[26];
        fill(lastSeen, lastSeen + 26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            prev[i] = lastSeen[c];
            lastSeen[c] = i;
        }
        fill(lastSeen, lastSeen + 26, n);
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'A';
            next[i] = lastSeen[c];
            lastSeen[c] = i;
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += (long long)(i - prev[i]) * (next[i] - i);
        }
        return (int)total;
    }
};
