// @leetcode id=3498 questionId=3811 slug=reverse-degree-of-a-string lang=cpp site=leetcode.com title="Reverse Degree of a String"
class Solution {
public:
    int reverseDegree(string s) {
        long long total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int reversedAlphaIdx = 26 - (s[i] - 'a');
            total += (long long)reversedAlphaIdx * (i + 1);
        }
        return (int)total;
    }
};
