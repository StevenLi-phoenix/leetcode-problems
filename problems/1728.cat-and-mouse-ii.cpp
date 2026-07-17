// @leetcode id=1728 questionId=1727 slug=cat-and-mouse-ii lang=cpp site=leetcode.com title="Cat and Mouse II"
class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int rows = grid.size(), cols = grid[0].size();
        int R = rows, C = cols;
        auto idx = [&](int r, int c) { return r * C + c; };
        int N = R * C;

        int mouseStart = -1, catStart = -1, food = -1;
        vector<bool> isWall(N, false);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                char ch = grid[r][c];
                int id = idx(r, c);
                if (ch == '#') isWall[id] = true;
                else if (ch == 'M') mouseStart = id;
                else if (ch == 'C') catStart = id;
                else if (ch == 'F') food = id;
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        auto buildMoves = [&](int jump) {
            vector<vector<int>> moves(N);
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    int id = idx(r, c);
                    if (isWall[id]) continue;
                    moves[id].push_back(id); // stay
                    for (int d = 0; d < 4; d++) {
                        for (int step = 1; step <= jump; step++) {
                            int nr = r + dr[d] * step, nc = c + dc[d] * step;
                            if (nr < 0 || nr >= R || nc < 0 || nc >= C) break;
                            int nid = idx(nr, nc);
                            if (isWall[nid]) break;
                            moves[id].push_back(nid);
                        }
                    }
                }
            }
            return moves;
        };

        vector<vector<int>> mouseMoves = buildMoves(mouseJump);
        vector<vector<int>> catMoves = buildMoves(catJump);

        // color: 0 unknown, 1 mouse win, 2 cat win
        // state index: (m*N + c)*2 + turn ; turn 0 = mouse to move, 1 = cat to move
        int totalStates = N * N * 2;
        vector<int> color(totalStates, 0);
        vector<int> degree(totalStates, 0);

        auto stateId = [&](int m, int c, int turn) { return (m * N + c) * 2 + turn; };

        for (int m = 0; m < N; m++) {
            for (int c = 0; c < N; c++) {
                if (isWall[m] || isWall[c]) continue;
                degree[stateId(m, c, 0)] = mouseMoves[m].size();
                degree[stateId(m, c, 1)] = catMoves[c].size();
            }
        }

        queue<int> q;
        for (int m = 0; m < N; m++) {
            for (int c = 0; c < N; c++) {
                if (isWall[m] || isWall[c]) continue;
                for (int turn = 0; turn < 2; turn++) {
                    int sid = stateId(m, c, turn);
                    if (m == c) { color[sid] = 2; q.push(sid); }
                    else if (m == food) { color[sid] = 1; q.push(sid); }
                    else if (c == food) { color[sid] = 2; q.push(sid); }
                }
            }
        }

        while (!q.empty()) {
            int sid = q.front(); q.pop();
            int turn = sid % 2;
            int mc = sid / 2;
            int c = mc % N;
            int m = mc / N;
            int winner = color[sid];

            int prevTurn = 1 - turn;
            if (prevTurn == 0) {
                // mouse moved into m from m_prev, cat position c unchanged
                for (int m_prev : mouseMoves[m]) {
                    if (isWall[m_prev]) continue;
                    int psid = stateId(m_prev, c, 0);
                    if (color[psid] != 0) continue;
                    if (winner == 1) {
                        color[psid] = 1;
                        q.push(psid);
                    } else {
                        degree[psid]--;
                        if (degree[psid] == 0) {
                            color[psid] = 2;
                            q.push(psid);
                        }
                    }
                }
            } else {
                // cat moved into c from c_prev, mouse position m unchanged
                for (int c_prev : catMoves[c]) {
                    if (isWall[c_prev]) continue;
                    int psid = stateId(m, c_prev, 1);
                    if (color[psid] != 0) continue;
                    if (winner == 2) {
                        color[psid] = 2;
                        q.push(psid);
                    } else {
                        degree[psid]--;
                        if (degree[psid] == 0) {
                            color[psid] = 1;
                            q.push(psid);
                        }
                    }
                }
            }
        }

        return color[stateId(mouseStart, catStart, 0)] == 1;
    }
};
