// @leetcode id=567 questionId=567 slug=permutation-in-string lang=cpp site=leetcode.com title="Permutation in String"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        int need[26] = {}, window[26] = {};
        for (char c : s1) need[c - 'a']++;
        for (int i = 0; i < n; i++) window[s2[i] - 'a']++;
        if (equal(need, need + 26, window)) return true;

        for (int i = n; i < m; i++) {
            window[s2[i] - 'a']++;
            window[s2[i - n] - 'a']--;
            if (equal(need, need + 26, window)) return true;
        }
        return false;
    }
};
