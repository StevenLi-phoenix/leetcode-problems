// @leetcode id=1790 questionId=1915 slug=check-if-one-string-swap-can-make-strings-equal lang=cpp site=leetcode.com title="Check if One String Swap Can Make Strings Equal"
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffs;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffs.push_back(i);
            }
        }

        if (diffs.size() == 0) return true;
        if (diffs.size() != 2) return false;

        int i = diffs[0], j = diffs[1];
        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};
