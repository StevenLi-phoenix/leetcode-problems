// @leetcode id=130 questionId=130 slug=surrounded-regions lang=cpp site=leetcode.com title="Surrounded Regions"
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        // DFS to mark border-connected 'O's as safe
        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
            board[r][c] = 'S'; // safe
            dfs(r+1, c); dfs(r-1, c); dfs(r, c+1); dfs(r, c-1);
        };
        
        // Mark all border-connected 'O's
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n-1);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j);
            dfs(m-1, j);
        }
        
        // Convert: remaining 'O' -> 'X', 'S' -> 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};
