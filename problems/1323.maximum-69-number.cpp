// @leetcode id=1323 questionId=1448 slug=maximum-69-number lang=cpp site=leetcode.com title="Maximum 69 Number"
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (char& c : s) {
            if (c == '6') { c = '9'; break; }
        }
        return stoi(s);
    }
};
