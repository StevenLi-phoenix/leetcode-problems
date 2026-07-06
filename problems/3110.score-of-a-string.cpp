// @leetcode id=3110 questionId=3379 slug=score-of-a-string lang=cpp site=leetcode.com title="Score of a String"
class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        for (int i = 0; i + 1 < (int)s.size(); ++i) {
            total += abs(s[i] - s[i + 1]);
        }
        return total;
    }
};
