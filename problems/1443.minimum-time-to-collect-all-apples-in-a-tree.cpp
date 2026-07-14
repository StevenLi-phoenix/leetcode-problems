// @leetcode id=1443 questionId=1554 slug=minimum-time-to-collect-all-apples-in-a-tree lang=cpp site=leetcode.com title="Minimum Time to Collect All Apples in a Tree"
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool>* apple;

    int dfs(int node, int parent) {
        int total = 0;
        for (int child : adj[node]) {
            if (child == parent) continue;
            int childCost = dfs(child, node);
            if (childCost > 0 || (*apple)[child]) {
                total += childCost + 2;
            }
        }
        return total;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        apple = &hasApple;
        return dfs(0, -1);
    }
};
