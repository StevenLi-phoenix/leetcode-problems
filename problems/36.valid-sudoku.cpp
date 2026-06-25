// @leetcode id=36 questionId=36 slug=valid-sudoku lang=cpp site=leetcode.com title="Valid Sudoku"
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (seen.count(c)) return false;
                    seen.insert(c);
                }
            }
        }
        
        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c != '.') {
                    if (seen.count(c)) return false;
                    seen.insert(c);
                }
            }
        }
        
        // Check 3x3 boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> seen;
                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {
                        char c = board[i][j];
                        if (c != '.') {
                            if (seen.count(c)) return false;
                            seen.insert(c);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
