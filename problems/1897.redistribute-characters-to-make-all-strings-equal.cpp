// @leetcode id=1897 questionId=2025 slug=redistribute-characters-to-make-all-strings-equal lang=cpp site=leetcode.com title="Redistribute Characters to Make All Strings Equal"
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count[26] = {0};
        for (const string& w : words) {
            for (char c : w) count[c - 'a']++;
        }
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            if (count[i] % n != 0) return false;
        }
        return true;
    }
};
