// @leetcode id=802 questionId=820 slug=find-eventual-safe-states lang=cpp site=leetcode.com title="Find Eventual Safe States"
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // Reverse-graph BFS from terminal nodes: a node is safe once every
        // one of its outgoing edges has been confirmed to lead to a safe node.
        vector<vector<int>> radj(n);
        vector<int> outdeg(n);
        for (int u = 0; u < n; u++) {
            outdeg[u] = graph[u].size();
            for (int v : graph[u]) radj[v].push_back(u);
        }

        vector<bool> safe(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (outdeg[i] == 0) { safe[i] = true; q.push(i); }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : radj[v])
                if (--outdeg[u] == 0) { safe[u] = true; q.push(u); }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (safe[i]) ans.push_back(i);
        return ans;
    }
};
