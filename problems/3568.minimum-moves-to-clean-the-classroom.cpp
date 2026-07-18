// @leetcode id=3568 questionId=3870 slug=minimum-moves-to-clean-the-classroom lang=cpp site=leetcode.com title="Minimum Moves to Clean the Classroom"
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litterCells;
        unordered_map<int, int> litterIndex; // r*n+c -> bit index

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') { sr = r; sc = c; }
                else if (classroom[r][c] == 'L') {
                    litterIndex[r * n + c] = litterCells.size();
                    litterCells.push_back({r, c});
                }
            }
        }

        int numLitter = litterCells.size();
        int fullMask = (1 << numLitter) - 1;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy + 1, vector<bool>(1 << numLitter, false))));

        int startMask = 0;
        auto it0 = litterIndex.find(sr * n + sc);
        if (it0 != litterIndex.end()) startMask |= (1 << it0->second);

        if (startMask == fullMask) return 0;

        queue<tuple<int,int,int,int,int>> q; // r,c,energyLeft,mask,dist
        q.push({sr, sc, energy, startMask, 0});
        visited[sr][sc][energy][startMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask, dist] = q.front();
            q.pop();

            if (e == 0) continue; // can't move further unless it's R, but R already reset upon arrival

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;

                int ne = e - 1;
                int nmask = mask;

                auto itL = litterIndex.find(nr * n + nc);
                if (itL != litterIndex.end()) nmask |= (1 << itL->second);

                if (classroom[nr][nc] == 'R') ne = energy;

                if (nmask == fullMask) return dist + 1;

                if (!visited[nr][nc][ne][nmask]) {
                    visited[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};
