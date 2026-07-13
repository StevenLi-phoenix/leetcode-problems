// @leetcode id=168 questionId=168 slug=excel-sheet-column-title lang=cpp site=leetcode.com title="Excel Sheet Column Title"
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--;
            result += char('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
