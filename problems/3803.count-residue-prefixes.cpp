// @leetcode id=3803 questionId=4186 slug=count-residue-prefixes lang=cpp site=leetcode.com title="Count Residue Prefixes"
class Solution {
public:
    int residuePrefixes(string s) {
        bool seen[26] = {false};
        int distinct = 0, count = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (!seen[c]) {
                seen[c] = true;
                distinct++;
            }
            if (distinct == (i + 1) % 3) count++;
        }
        return count;
    }
};
