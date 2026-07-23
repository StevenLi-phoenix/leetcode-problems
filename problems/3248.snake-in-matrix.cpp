// @leetcode id=3248 questionId=3533 slug=snake-in-matrix lang=cpp site=leetcode.com title="Snake in Matrix"
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;
        for (const string& c : commands) {
            if (c == "UP") row--;
            else if (c == "DOWN") row++;
            else if (c == "LEFT") col--;
            else if (c == "RIGHT") col++;
        }
        return row * n + col;
    }
};
