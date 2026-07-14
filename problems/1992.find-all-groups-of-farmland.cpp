// @leetcode id=1992 questionId=2103 slug=find-all-groups-of-farmland lang=cpp site=leetcode.com title="Find All Groups of Farmland"
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) continue;
                if (i > 0 && land[i - 1][j] == 1) continue;
                if (j > 0 && land[i][j - 1] == 1) continue;

                int r2 = i;
                while (r2 + 1 < m && land[r2 + 1][j] == 1) r2++;
                int c2 = j;
                while (c2 + 1 < n && land[i][c2 + 1] == 1) c2++;

                result.push_back({i, j, r2, c2});
            }
        }
        return result;
    }
};
