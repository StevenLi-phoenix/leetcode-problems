// @leetcode id=1615 questionId=1738 slug=maximal-network-rank lang=cpp site=leetcode.com title="Maximal Network Rank"
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for (auto& r : roads) {
            degree[r[0]]++;
            degree[r[1]]++;
            connected[r[0]][r[1]] = true;
            connected[r[1]][r[0]] = true;
        }

        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j] - (connected[i][j] ? 1 : 0);
                best = max(best, rank);
            }
        }
        return best;
    }
};
