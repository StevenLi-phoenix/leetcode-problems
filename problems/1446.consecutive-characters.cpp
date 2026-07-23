// @leetcode id=1446 questionId=1542 slug=consecutive-characters lang=cpp site=leetcode.com title="Consecutive Characters"
class Solution {
public:
    int maxPower(string s) {
        int best = 1, current = 1;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == s[i - 1]) {
                current++;
            } else {
                current = 1;
            }
            best = max(best, current);
        }
        return best;
    }
};
