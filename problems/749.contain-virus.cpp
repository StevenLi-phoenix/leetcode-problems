// @leetcode id=749 questionId=750 slug=contain-virus lang=cpp site=leetcode.com title="Contain Virus"
class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size();
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        int totalWalls = 0;

        while (true) {
            vector<vector<int>> regionId(m, vector<int>(n, -1));
            vector<vector<pair<int,int>>> regionCells;
            vector<set<pair<int,int>>> regionThreatened;
            vector<int> regionWalls;

            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (isInfected[r][c] == 1 && regionId[r][c] == -1) {
                        int id = regionCells.size();
                        regionCells.push_back({});
                        regionThreatened.push_back({});
                        regionWalls.push_back(0);

                        queue<pair<int,int>> q;
                        q.push({r, c});
                        regionId[r][c] = id;

                        while (!q.empty()) {
                            auto [cr, cc] = q.front(); q.pop();
                            regionCells[id].push_back({cr, cc});
                            for (int d = 0; d < 4; d++) {
                                int nr = cr + dr[d], nc = cc + dc[d];
                                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                                if (isInfected[nr][nc] == 1 && regionId[nr][nc] == -1) {
                                    regionId[nr][nc] = id;
                                    q.push({nr, nc});
                                } else if (isInfected[nr][nc] == 0) {
                                    regionThreatened[id].insert({nr, nc});
                                    regionWalls[id]++;
                                }
                            }
                        }
                    }
                }
            }

            if (regionCells.empty()) break;

            int best = -1, bestThreat = -1;
            for (int i = 0; i < (int)regionCells.size(); i++) {
                if ((int)regionThreatened[i].size() > bestThreat) {
                    bestThreat = regionThreatened[i].size();
                    best = i;
                }
            }

            if (bestThreat == 0) break;

            totalWalls += regionWalls[best];
            for (auto& [r, c] : regionCells[best]) isInfected[r][c] = 2;

            for (int i = 0; i < (int)regionCells.size(); i++) {
                if (i == best) continue;
                for (auto& [r, c] : regionThreatened[i]) isInfected[r][c] = 1;
            }
        }

        return totalWalls;
    }
};
