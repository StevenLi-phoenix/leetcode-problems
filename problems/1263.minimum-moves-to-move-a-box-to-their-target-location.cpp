// @leetcode id=1263 questionId=1389 slug=minimum-moves-to-move-a-box-to-their-target-location lang=cpp site=leetcode.com title="Minimum Moves to Move a Box to Their Target Location"
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int boxR = -1, boxC = -1, playerR = -1, playerC = -1, targetR = -1, targetC = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') { boxR = i; boxC = j; }
                else if (grid[i][j] == 'S') { playerR = i; playerC = j; }
                else if (grid[i][j] == 'T') { targetR = i; targetC = j; }
            }
        }

        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n, INT_MAX))));

        deque<array<int,4>> dq;
        dist[boxR][boxC][playerR][playerC] = 0;
        dq.push_back({boxR, boxC, playerR, playerC});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [br, bc, pr, pc] = dq.front();
            dq.pop_front();
            int d = dist[br][bc][pr][pc];

            if (br == targetR && bc == targetC) return d;

            for (int k = 0; k < 4; k++) {
                int npr = pr + dr[k], npc = pc + dc[k];
                if (npr < 0 || npr >= m || npc < 0 || npc >= n || grid[npr][npc] == '#') continue;

                if (npr == br && npc == bc) {
                    int nbr = br + dr[k], nbc = bc + dc[k];
                    if (nbr < 0 || nbr >= m || nbc < 0 || nbc >= n || grid[nbr][nbc] == '#') continue;
                    if (dist[nbr][nbc][npr][npc] > d + 1) {
                        dist[nbr][nbc][npr][npc] = d + 1;
                        dq.push_back({nbr, nbc, npr, npc});
                    }
                } else {
                    if (dist[br][bc][npr][npc] > d) {
                        dist[br][bc][npr][npc] = d;
                        dq.push_front({br, bc, npr, npc});
                    }
                }
            }
        }

        return -1;
    }
};
