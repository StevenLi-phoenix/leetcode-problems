// @leetcode id=1584 questionId=1706 slug=min-cost-to-connect-all-points lang=cpp site=leetcode.com title="Min Cost to Connect All Points"
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        minDist[0] = 0;
        int totalCost = 0;
        
        for (int i = 0; i < n; i++) {
            // Find unvisited node with minimum distance
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            
            visited[u] = true;
            totalCost += minDist[u];
            
            // Update distances to neighbors
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }
        
        return totalCost;
    }
};
