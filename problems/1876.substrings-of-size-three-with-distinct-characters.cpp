// @leetcode id=1876 questionId=1987 slug=substrings-of-size-three-with-distinct-characters lang=cpp site=leetcode.com title="Substrings of Size Three with Distinct Characters"
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for (int i = 0; i + 2 < (int)s.size(); i++) {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) count++;
        }
        return count;
    }
};
