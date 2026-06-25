// @leetcode id=2322 questionId=2400 slug=minimum-score-after-removals-on-a-tree lang=cpp site=leetcode.com title="Minimum Score After Removals on a Tree"
class Solution {
public:
    int n;
    vector<int> in_time, out_time, xorVal;
    vector<vector<int>> adj;
    int timer_val = 0;
    
    void dfs(int node, int parent, vector<int>& nums) {
        in_time[node] = timer_val++;
        xorVal[node] = nums[node];
        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node, nums);
                xorVal[node] ^= xorVal[child];
            }
        }
        out_time[node] = timer_val++;
    }
    
    bool isAncestor(int u, int v) {
        // Is u an ancestor of v?
        return in_time[u] <= in_time[v] && out_time[v] <= out_time[u];
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        adj.assign(n, {});
        in_time.resize(n);
        out_time.resize(n);
        xorVal.resize(n);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1, nums);
        
        int totalXor = xorVal[0];
        int result = INT_MAX;
        
        // For each pair of edges
        for (int i = 0; i < (int)edges.size(); i++) {
            for (int j = i + 1; j < (int)edges.size(); j++) {
                // Each edge connects parent to child; the child's subtree is xorVal[child]
                // Find child node for each edge (the one that is not the root's side)
                // In rooted tree, child is the one with larger in_time
                int u = edges[i][0], v = edges[i][1];
                // child of edge i is the node that's deeper (has parent)
                int c1 = (in_time[u] > in_time[v]) ? u : v; // c1 is the "child" endpoint
                
                int p = edges[j][0], q = edges[j][1];
                int c2 = (in_time[p] > in_time[q]) ? p : q;
                
                int x1 = xorVal[c1], x2 = xorVal[c2];
                
                int a, b, c;
                if (isAncestor(c1, c2)) {
                    // c2's subtree is inside c1's subtree
                    a = x2;
                    b = x1 ^ x2;
                    c = totalXor ^ x1;
                } else if (isAncestor(c2, c1)) {
                    // c1's subtree is inside c2's subtree
                    a = x1;
                    b = x2 ^ x1;
                    c = totalXor ^ x2;
                } else {
                    // Disjoint
                    a = x1;
                    b = x2;
                    c = totalXor ^ x1 ^ x2;
                }
                
                int maxVal = max({a, b, c});
                int minVal = min({a, b, c});
                result = min(result, maxVal - minVal);
            }
        }
        
        return result;
    }
};
