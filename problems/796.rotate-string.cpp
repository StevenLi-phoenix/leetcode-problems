// @leetcode id=796 questionId=812 slug=rotate-string lang=cpp site=leetcode.com title="Rotate String"
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};
