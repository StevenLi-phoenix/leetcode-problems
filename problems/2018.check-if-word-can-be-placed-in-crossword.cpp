// @leetcode id=2018 questionId=2146 slug=check-if-word-can-be-placed-in-crossword lang=cpp site=leetcode.com title="Check if Word Can Be Placed In Crossword"
class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int L = word.size();

        // A run [start, end) (indices into `get(idx)`) fits only if the word exactly
        // fills it — anything shorter would leave a space/letter just past either end.
        auto checkRun = [&](int start, int end, auto&& get) -> bool {
            if (end - start != L) return false;
            bool fwd = true, bwd = true;
            for (int k = 0; k < L && (fwd || bwd); ++k) {
                char c = get(start + k);
                if (fwd && !(c == ' ' || c == word[k])) fwd = false;
                if (bwd && !(c == ' ' || c == word[L - 1 - k])) bwd = false;
            }
            return fwd || bwd;
        };

        for (int r = 0; r < m; ++r) {
            auto get = [&](int c) { return board[r][c]; };
            int start = 0;
            for (int c = 0; c <= n; ++c) {
                if (c == n || board[r][c] == '#') {
                    if (checkRun(start, c, get)) return true;
                    start = c + 1;
                }
            }
        }

        for (int c = 0; c < n; ++c) {
            auto get = [&](int r) { return board[r][c]; };
            int start = 0;
            for (int r = 0; r <= m; ++r) {
                if (r == m || board[r][c] == '#') {
                    if (checkRun(start, r, get)) return true;
                    start = r + 1;
                }
            }
        }

        return false;
    }
};
