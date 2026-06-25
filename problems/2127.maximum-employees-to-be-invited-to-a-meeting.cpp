// @leetcode id=2127 questionId=2246 slug=maximum-employees-to-be-invited-to-a-meeting lang=cpp site=leetcode.com title="Maximum Employees to Be Invited to a Meeting"
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }
        
        // Topological sort to remove non-cycle nodes
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        // depth[i] = longest chain ending at node i (from outside cycle)
        vector<int> depth(n, 1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int v = favorite[u];
            depth[v] = max(depth[v], depth[u] + 1);
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
        
        // Now find cycles - nodes with indegree > 0 are in cycles
        int ans = 0;
        int sumLen2Cycles = 0;
        
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && indegree[i] > 0) {
                // Traverse the cycle
                int cycleLen = 0;
                int cur = i;
                while (!visited[cur]) {
                    visited[cur] = true;
                    cycleLen++;
                    cur = favorite[cur];
                }
                
                if (cycleLen == 2) {
                    // For 2-cycles, we can extend with chains from both ends
                    // i and favorite[i] form the cycle
                    sumLen2Cycles += depth[i] + depth[favorite[i]];
                } else {
                    ans = max(ans, cycleLen);
                }
            }
        }
        
        ans = max(ans, sumLen2Cycles);
        return ans;
    }
};
