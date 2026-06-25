// @leetcode id=3715 questionId=3957 slug=sum-of-perfect-square-ancestors lang=cpp site=leetcode.com title="Sum of Perfect Square Ancestors"
class Solution {
public:
    // Compute square-free part of n
    int squareFree(int n) {
        int result = 1;
        for (int p = 2; (long long)p * p <= n; p++) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            if (cnt % 2 == 1) result *= p;
        }
        if (n > 1) result *= n;
        return result;
    }
    
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Precompute square-free parts
        vector<int> sf(n);
        for (int i = 0; i < n; i++) sf[i] = squareFree(nums[i]);
        
        long long ans = 0;
        unordered_map<int, int> pathCount;
        
        // DFS iterative with parent tracking
        // Use explicit stack: (node, parent, entering)
        vector<pair<int,int>> stk;
        stk.push_back({0, -1});
        vector<bool> visited(n, false);
        
        // We need to properly do DFS with backtracking
        // Use (node, parent, phase) where phase 0 = enter, 1 = exit
        vector<tuple<int,int,int>> stack2;
        stack2.push_back({0, -1, 0});
        
        while (!stack2.empty()) {
            auto [node, par, phase] = stack2.back();
            stack2.pop_back();
            
            if (phase == 1) {
                // Exiting: remove from path
                pathCount[sf[node]]--;
                if (pathCount[sf[node]] == 0) pathCount.erase(sf[node]);
                continue;
            }
            
            // Entering: add to path count exit marker
            stack2.push_back({node, par, 1});
            
            // Count ancestors with same squareFree as this node
            // (node 0 is root, don't count itself)
            if (node != 0) {
                auto it = pathCount.find(sf[node]);
                if (it != pathCount.end()) ans += it->second;
            }
            
            // Add to path
            pathCount[sf[node]]++;
            
            // Push children
            for (int child : adj[node]) {
                if (child != par) {
                    stack2.push_back({child, node, 0});
                }
            }
        }
        
        return ans;
    }
};
