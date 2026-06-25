// @leetcode id=1784 questionId=1910 slug=check-if-binary-string-has-at-most-one-segment-of-ones lang=cpp site=leetcode.com title="Check if Binary String Has at Most One Segment of Ones"
class Solution {
    public:
    bool checkOnesSegment(string s) {
    return s.find("01") == string::npos;
    }
    };
