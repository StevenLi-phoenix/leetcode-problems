// @leetcode id=1861 questionId=1972 slug=rotating-the-box lang=cpp site=leetcode.com title="Rotating the Box"
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        
        // Step 1: Apply gravity - stones fall to the right in each row
        for (int i = 0; i < m; i++) {
            int emptyPos = n - 1; // rightmost position a stone can fall to
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    // obstacle: reset emptyPos to left of obstacle
                    emptyPos = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    // stone: move it to emptyPos
                    boxGrid[i][j] = '.';
                    boxGrid[i][emptyPos] = '#';
                    emptyPos--;
                }
            }
        }
        
        // Step 2: Rotate 90 degrees clockwise
        // New dimensions: n rows, m cols
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return result;
    }
};
