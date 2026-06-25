// @leetcode id=709 questionId=742 slug=to-lower-case lang=cpp site=leetcode.com title="To Lower Case"
class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        return s;
    }
};
