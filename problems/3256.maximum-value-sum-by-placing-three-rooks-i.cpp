// @leetcode id=3256 questionId=3550 slug=maximum-value-sum-by-placing-three-rooks-i lang=cpp site=leetcode.com title="Maximum Value Sum by Placing Three Rooks I"
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        // Top 3 (value, col) per row is always enough to find an optimal
        // 3-rook placement, since at most 2 other rooks could otherwise
        // occupy the same columns.
        vector<vector<pair<int, int>>> top(m);
        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> row;
            for (int j = 0; j < n; j++) row.push_back({board[i][j], j});
            sort(row.rbegin(), row.rend());
            if ((int)row.size() > 3) row.resize(3);
            top[i] = row;
        }

        long long best = LLONG_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    for (auto& [v1, c1] : top[i]) {
                        for (auto& [v2, c2] : top[j]) {
                            if (c2 == c1) continue;
                            for (auto& [v3, c3] : top[k]) {
                                if (c3 == c1 || c3 == c2) continue;
                                best = max(best, (long long)v1 + v2 + v3);
                            }
                        }
                    }
                }
            }
        }
        return best;
    }
};
