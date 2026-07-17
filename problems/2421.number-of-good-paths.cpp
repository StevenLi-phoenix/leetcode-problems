// @leetcode id=2421 questionId=2505 slug=number-of-good-paths lang=cpp site=leetcode.com title="Number of Good Paths"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        map<int, vector<int>> byValue;
        for (int i = 0; i < n; i++) byValue[vals[i]].push_back(i);

        long long answer = n;

        for (auto& [v, nodes] : byValue) {
            for (int u : nodes) {
                for (int w : adj[u]) {
                    if (vals[w] <= v) unite(u, w);
                }
            }

            unordered_map<int,int> rootCount;
            for (int u : nodes) rootCount[find(u)]++;

            for (auto& [root, cnt] : rootCount) {
                answer += (long long)cnt * (cnt - 1) / 2;
            }
        }

        return (int)answer;
    }
};
