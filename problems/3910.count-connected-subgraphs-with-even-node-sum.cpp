// @leetcode id=3910 questionId=4279 slug=count-connected-subgraphs-with-even-node-sum lang=cpp site=leetcode.com title="Count Connected Subgraphs with Even Node Sum"
class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        // Build adjacency for quick lookup
        // For each subset, check connectivity using BFS/DFS
        // n <= 13, so 2^13 = 8192 subsets
        
        // Precompute adjacency bitmask for each node
        vector<int> adj(n, 0);
        for (auto& e : edges) {
            adj[e[0]] |= (1 << e[1]);
            adj[e[1]] |= (1 << e[0]);
        }
        
        int ans = 0;
        
        for (int mask = 1; mask < (1 << n); mask++) {
            // Compute sum parity
            int sumParity = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    sumParity ^= nums[i];
                }
            }
            if (sumParity != 0) continue; // sum is odd, skip
            
            // Check connectivity using BFS
            // Find first set bit
            int start = __builtin_ctz(mask);
            int visited = (1 << start);
            queue<int> q;
            q.push(start);
            
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                // Neighbors in mask
                int neighbors = adj[cur] & mask & ~visited;
                visited |= neighbors;
                while (neighbors) {
                    int nb = __builtin_ctz(neighbors);
                    q.push(nb);
                    neighbors &= neighbors - 1;
                }
            }
            
            if (visited == mask) {
                ans++;
            }
        }
        
        return ans;
    }
};
