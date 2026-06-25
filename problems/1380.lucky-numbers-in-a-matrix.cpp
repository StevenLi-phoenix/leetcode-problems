// @leetcode id=1380 questionId=1496 slug=lucky-numbers-in-a-matrix lang=cpp site=leetcode.com title="Lucky Numbers in a Matrix"
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result;

        for (int i = 0; i < m; i++) {
            int minVal = matrix[i][0];
            int minCol = 0;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minCol = j;
                }
            }

            bool isLucky = true;
            for (int k = 0; k < m; k++) {
                if (matrix[k][minCol] > minVal) {
                    isLucky = false;
                    break;
                }
            }

            if (isLucky) {
                result.push_back(minVal);
            }
        }

        return result;
    }
};
