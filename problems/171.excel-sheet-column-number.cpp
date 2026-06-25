// @leetcode id=171 questionId=171 slug=excel-sheet-column-number lang=cpp site=leetcode.com title="Excel Sheet Column Number"
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};
