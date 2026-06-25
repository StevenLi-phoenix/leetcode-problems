// @leetcode id=3612 questionId=3931 slug=process-string-with-special-operations-i lang=cpp site=leetcode.com title="Process String with Special Operations I"
class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) result.pop_back();
            } else if (c == '#') {
                result = result + result;
            } else if (c == '%') {
                reverse(result.begin(), result.end());
            } else {
                result += c;
            }
        }
        return result;
    }
};
