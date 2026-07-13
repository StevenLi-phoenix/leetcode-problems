// @leetcode id=3127 questionId=3398 slug=make-a-square-with-the-same-color lang=cpp site=leetcode.com title="Make a Square with the Same Color"
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int whites = 0;
                for (int di = 0; di < 2; di++) {
                    for (int dj = 0; dj < 2; dj++) {
                        if (grid[i + di][j + dj] == 'W') whites++;
                    }
                }
                if (whites != 2) return true; // 0,1,3,4 whites means <=1 change needed
            }
        }
        return false;
    }
};
