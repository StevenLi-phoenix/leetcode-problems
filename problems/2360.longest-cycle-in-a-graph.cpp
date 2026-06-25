// @leetcode id=2360 questionId=2439 slug=longest-cycle-in-a-graph lang=cpp site=leetcode.com title="Longest Cycle in a Graph"
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, -1); // -1 = unvisited, >= 0 = time of first visit
        int ans = -1;
        int timer = 0;
        
        for (int start = 0; start < n; start++) {
            if (visited[start] != -1) continue;
            
            // Follow the path from start
            int node = start;
            int startTime = timer;
            
            while (node != -1 && visited[node] == -1) {
                visited[node] = timer++;
                node = edges[node];
            }
            
            // If node != -1 and visited[node] >= startTime, we found a cycle
            if (node != -1 && visited[node] >= startTime) {
                int cycleLen = timer - visited[node];
                ans = max(ans, cycleLen);
            }
        }
        
        return ans;
    }
};
