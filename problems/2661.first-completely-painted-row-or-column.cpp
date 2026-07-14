// @leetcode id=2661 questionId=2685 slug=first-completely-painted-row-or-column lang=cpp site=leetcode.com title="First Completely Painted Row or Column"
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> pos;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) pos[mat[r][c]] = {r, c};
        }

        vector<int> rowCount(m, 0), colCount(n, 0);
        for (int i = 0; i < (int)arr.size(); i++) {
            auto [r, c] = pos[arr[i]];
            rowCount[r]++;
            colCount[c]++;
            if (rowCount[r] == n || colCount[c] == m) return i;
        }
        return -1;
    }
};
