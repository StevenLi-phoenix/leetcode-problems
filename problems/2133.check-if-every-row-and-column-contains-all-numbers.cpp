// @leetcode id=2133 questionId=2254 slug=check-if-every-row-and-column-contains-all-numbers lang=cpp site=leetcode.com title="Check if Every Row and Column Contains All Numbers"
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int r = 0; r < n; r++) {
            vector<bool> seen(n + 1, false);
            for (int c = 0; c < n; c++) {
                int v = matrix[r][c];
                if (seen[v]) return false;
                seen[v] = true;
            }
        }

        for (int c = 0; c < n; c++) {
            vector<bool> seen(n + 1, false);
            for (int r = 0; r < n; r++) {
                int v = matrix[r][c];
                if (seen[v]) return false;
                seen[v] = true;
            }
        }

        return true;
    }
};
