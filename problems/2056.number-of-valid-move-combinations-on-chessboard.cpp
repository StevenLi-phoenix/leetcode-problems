// @leetcode id=2056 questionId=2166 slug=number-of-valid-move-combinations-on-chessboard lang=cpp site=leetcode.com title="Number of Valid Move Combinations On Chessboard"
class Solution {
    // A move is (dr, dc, dist); dist = 0 means the piece stays put.
    struct Move { int dr, dc, dist; };

    static bool inBoard(int r, int c) { return r >= 1 && r <= 8 && c >= 1 && c <= 8; }

    // Square piece i occupies at second t under move m.
    static pair<int, int> at(const vector<int>& start, const Move& m, int t) {
        int step = min(t, m.dist);
        return {start[0] + m.dr * step, start[1] + m.dc * step};
    }

public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        static const int ROOK[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        static const int BISHOP[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};

        vector<vector<Move>> moves(n);
        for (int i = 0; i < n; i++) {
            moves[i].push_back({0, 0, 0});
            vector<pair<int,int>> dirs;
            if (pieces[i] != "bishop")
                for (auto& d : ROOK) dirs.push_back({d[0], d[1]});
            if (pieces[i] != "rook")
                for (auto& d : BISHOP) dirs.push_back({d[0], d[1]});
            for (auto [dr, dc] : dirs)
                for (int dist = 1; dist <= 7; dist++) {
                    if (!inBoard(positions[i][0] + dr * dist, positions[i][1] + dc * dist)) break;
                    moves[i].push_back({dr, dc, dist});
                }
        }

        vector<Move> chosen(n);
        int ans = 0;
        // Backtrack piece by piece; a new move must avoid every earlier piece
        // at every second (both keep standing on their final square afterwards).
        auto dfs = [&](auto&& self, int i) -> void {
            if (i == n) { ans++; return; }
            for (const Move& m : moves[i]) {
                bool ok = true;
                for (int j = 0; j < i && ok; j++) {
                    int horizon = max(m.dist, chosen[j].dist);
                    for (int t = 1; t <= horizon; t++)
                        if (at(positions[i], m, t) == at(positions[j], chosen[j], t)) { ok = false; break; }
                }
                if (!ok) continue;
                chosen[i] = m;
                self(self, i + 1);
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
