// @leetcode id=3373 questionId=3645 slug=maximize-the-number-of-target-nodes-after-connecting-trees-ii lang=cpp site=leetcode.com title="Maximize the Number of Target Nodes After Connecting Trees II"
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> color1 = colorTree(edges1);
        vector<int> color2 = colorTree(edges2);

        int n = color1.size();
        int cnt1[2] = {0, 0};
        for (int c : color1) ++cnt1[c];

        int cnt2[2] = {0, 0};
        for (int c : color2) ++cnt2[c];
        int bestFromTree2 = max(cnt2[0], cnt2[1]);

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = cnt1[color1[i]] + bestFromTree2;
        }
        return ans;
    }

private:
    vector<int> colorTree(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(n, -1);
        color[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return color;
    }
};
