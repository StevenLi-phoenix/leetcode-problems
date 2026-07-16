// @leetcode id=438 questionId=438 slug=find-all-anagrams-in-a-string lang=cpp site=leetcode.com title="Find All Anagrams in a String"
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> result;
        if (m > n) return result;

        int need[26] = {0}, window[26] = {0};
        for (char c : p) need[c - 'a']++;

        for (int i = 0; i < n; i++) {
            window[s[i] - 'a']++;
            if (i >= m) window[s[i - m] - 'a']--;
            if (i >= m - 1) {
                bool match = true;
                for (int c = 0; c < 26; c++) {
                    if (window[c] != need[c]) { match = false; break; }
                }
                if (match) result.push_back(i - m + 1);
            }
        }
        return result;
    }
};
