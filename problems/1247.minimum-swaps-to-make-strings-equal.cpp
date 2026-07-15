// @leetcode id=1247 questionId=1369 slug=minimum-swaps-to-make-strings-equal lang=cpp site=leetcode.com title="Minimum Swaps to Make Strings Equal"
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] == 'x' && s2[i] == 'y') xy++;
            else if (s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        if ((xy + yx) % 2 != 0) return -1;
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
};
