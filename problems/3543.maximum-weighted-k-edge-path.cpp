// @leetcode id=3543 questionId=3856 slug=maximum-weighted-k-edge-path lang=cpp site=leetcode.com title="Maximum Weighted K-Edge Path"
class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        // dp[step][node] = set of all achievable path sums ending at node with exactly step edges
        // Only keep sums < t (since adding more positive edges would only increase sum)
        // Since k, n, t are all ≤ 300, 300, 600 respectively, and w_i ≤ 10
        // Max possible sum = k * max_w = 300 * 10 = 3000, but we only care about < t ≤ 600
        
        // Use unordered_set for each (step, node)
        // Or use bitset of size 600
        
        // dp[node] = set of achievable sums with current step count
        vector<unordered_set<int>> dp(n), ndp(n);
        
        // Base: 0 edges, each node has sum 0
        for (int i = 0; i < n; i++) {
            dp[i].insert(0);
        }
        
        int ans = -1;
        
        if (k == 0) {
            // Path with 0 edges has sum 0, which is < t (since t >= 1)
            return 0;
        }
        
        for (int step = 1; step <= k; step++) {
            // Clear ndp
            for (int i = 0; i < n; i++) ndp[i].clear();
            
            for (auto& e : edges) {
                int u = e[0], v = e[1], w = e[2];
                for (int s : dp[u]) {
                    int newS = s + w;
                    if (newS < t) {
                        ndp[v].insert(newS);
                    }
                }
            }
            
            dp = ndp;
            
            if (step == k) {
                for (int v = 0; v < n; v++) {
                    for (int s : dp[v]) {
                        ans = max(ans, s);
                    }
                }
            }
        }
        
        return ans;
    }
};
