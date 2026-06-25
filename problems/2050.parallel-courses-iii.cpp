// @leetcode id=2050 questionId=2176 slug=parallel-courses-iii lang=cpp site=leetcode.com title="Parallel Courses III"
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // dp[i] = minimum time to complete course i (1-indexed)
        // Use topological sort (Kahn's algorithm)
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        vector<int> dp(n + 1, 0);
        
        for (auto& r : relations) {
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i - 1];
            }
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : adj[cur]) {
                dp[next] = max(dp[next], dp[cur] + time[next - 1]);
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
