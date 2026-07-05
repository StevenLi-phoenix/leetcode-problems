// @leetcode id=3438 questionId=3736 slug=find-valid-pair-of-adjacent-digits-in-string lang=cpp site=leetcode.com title="Find Valid Pair of Adjacent Digits in String"
class Solution {
public:
    string findValidPair(string s) {
        int count[10] = {0};
        for (char c : s) ++count[c - '0'];

        for (int i = 0; i + 1 < (int)s.size(); ++i) {
            int a = s[i] - '0', b = s[i + 1] - '0';
            if (a != b && count[a] == a && count[b] == b) {
                return s.substr(i, 2);
            }
        }
        return "";
    }
};
