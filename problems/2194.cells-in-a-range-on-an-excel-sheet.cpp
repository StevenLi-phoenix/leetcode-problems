// @leetcode id=2194 questionId=2304 slug=cells-in-a-range-on-an-excel-sheet lang=cpp site=leetcode.com title="Cells in a Range on an Excel Sheet"
class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        for (char col = s[0]; col <= s[3]; ++col) {
            for (char row = s[1]; row <= s[4]; ++row) {
                result.push_back({col, row});
            }
        }
        return result;
    }
};
