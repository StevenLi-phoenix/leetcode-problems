// @leetcode id=2850 questionId=3092 slug=minimum-moves-to-spread-stones-over-grid lang=cpp site=leetcode.com title="Minimum Moves to Spread Stones Over Grid"
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> sources, sinks;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 1) {
                    for (int k = 0; k < grid[i][j] - 1; k++) sources.push_back({i, j});
                } else if (grid[i][j] == 0) {
                    sinks.push_back({i, j});
                }
            }
        }

        sort(sinks.begin(), sinks.end());
        int best = INT_MAX;
        do {
            int cost = 0;
            for (int i = 0; i < (int)sources.size(); i++) {
                cost += abs(sources[i].first - sinks[i].first) + abs(sources[i].second - sinks[i].second);
            }
            best = min(best, cost);
        } while (next_permutation(sinks.begin(), sinks.end()));

        return best;
    }
};
