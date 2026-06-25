// @leetcode id=434 questionId=434 slug=number-of-segments-in-a-string lang=cpp site=leetcode.com title="Number of Segments in a String"
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' '))
                count++;
        }
        return count;
    }
};
