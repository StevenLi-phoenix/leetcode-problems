// @leetcode id=797 questionId=813 slug=all-paths-from-source-to-target lang=cpp site=leetcode.com title="All Paths From Source to Target"
class Solution {
private:
    vector<vector<int>> result;
    
    void dfs(vector<vector<int>>& graph, int node, int n, vector<int>& path) {
        if (node == n - 1) {
            result.push_back(path);
            return;
        }
        
        for (int next : graph[node]) {
            path.push_back(next);
            dfs(graph, next, n, path);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path = {0};
        dfs(graph, 0, n, path);
        return result;
    }
};
