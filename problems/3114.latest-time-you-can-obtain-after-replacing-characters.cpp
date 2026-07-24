// @leetcode id=3114 questionId=3361 slug=latest-time-you-can-obtain-after-replacing-characters lang=cpp site=leetcode.com title="Latest Time You Can Obtain After Replacing Characters"
class Solution {
public:
    string findLatestTime(string s) {
        char h1 = s[0], h2 = s[1], m1 = s[3], m2 = s[4];

        if (h1 == '?') {
            h1 = (h2 == '?' || h2 <= '1') ? '1' : '0';
        }
        if (h2 == '?') {
            h2 = (h1 == '1') ? '1' : '9';
        }
        if (m1 == '?') m1 = '5';
        if (m2 == '?') m2 = '9';

        return string() + h1 + h2 + ':' + m1 + m2;
    }
};
