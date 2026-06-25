// @leetcode id=773 questionId=787 slug=sliding-puzzle lang=cpp site=leetcode.com title="Sliding Puzzle"
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        int zero_pos = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += char('0' + board[i][j]);
                if (board[i][j] == 0) zero_pos = i * 3 + j;
            }
        }

        if (start == target) return 0;

        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_map<string, int> visited;
        queue<pair<string, int>> q;

        q.push({start, zero_pos});
        visited[start] = 0;

        while (!q.empty()) {
            auto [curr, pos] = q.front();
            q.pop();
            int moves = visited[curr];

            for (int next_pos : neighbors[pos]) {
                string next = curr;
                swap(next[pos], next[next_pos]);

                if (next == target) return moves + 1;

                if (visited.find(next) == visited.end()) {
                    visited[next] = moves + 1;
                    q.push({next, next_pos});
                }
            }
        }

        return -1;
    }
};
