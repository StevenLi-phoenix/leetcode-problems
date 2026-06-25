// @leetcode id=806 questionId=824 slug=number-of-lines-to-write-string lang=cpp site=leetcode.com title="Number of Lines To Write String"
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int currentWidth = 0;

        for (char c : s) {
            int charWidth = widths[c - 'a'];
            if (currentWidth + charWidth <= 100) {
                currentWidth += charWidth;
            } else {
                lines++;
                currentWidth = charWidth;
            }
        }

        return {lines, currentWidth};
    }
};
