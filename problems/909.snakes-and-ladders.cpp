// @leetcode id=909 questionId=945 slug=snakes-and-ladders lang=cpp site=leetcode.com title="Snakes and Ladders"
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // Convert cell number (1-indexed) to board value
        auto getVal = [&](int cell) {
            int r = (cell - 1) / n;
            int c = (cell - 1) % n;
            // Row from bottom: row = n-1-r
            int row = n - 1 - r;
            // Boustrophedon: even rows (from bottom) go left-to-right, odd right-to-left
            int col = (r % 2 == 0) ? c : (n - 1 - c);
            return board[row][col];
        };
        int target = n * n;
        vector<bool> visited(target + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front(); q.pop();
                if (curr == target) return moves;
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > target) break;
                    int val = getVal(next);
                    if (val != -1) next = val;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
