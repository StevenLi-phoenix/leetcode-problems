// @leetcode id=1631 questionId=1753 slug=path-with-minimum-effort lang=cpp site=leetcode.com title="Path With Minimum Effort"
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        
        // {effort, row, col}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!pq.empty()) {
            auto [eff, r, c] = pq.top(); pq.pop();
            
            if (r == rows-1 && c == cols-1) return eff;
            if (eff > dist[r][c]) continue;
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                int newEff = max(eff, abs(heights[nr][nc] - heights[r][c]));
                if (newEff < dist[nr][nc]) {
                    dist[nr][nc] = newEff;
                    pq.push({newEff, nr, nc});
                }
            }
        }
        return 0;
    }
};
