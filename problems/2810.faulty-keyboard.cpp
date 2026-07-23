// @leetcode id=2810 questionId=2886 slug=faulty-keyboard lang=cpp site=leetcode.com title="Faulty Keyboard"
class Solution {
public:
    string finalString(string s) {
        string result;
        for (char c : s) {
            if (c == 'i') {
                reverse(result.begin(), result.end());
            } else {
                result += c;
            }
        }
        return result;
    }
};
