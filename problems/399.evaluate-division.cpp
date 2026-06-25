// @leetcode id=399 questionId=399 slug=evaluate-division lang=cpp site=leetcode.com title="Evaluate Division"
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < (int)equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double v = values[i];
            graph[a][b] = v;
            graph[b][a] = 1.0 / v;
        }
        auto bfs = [&](string src, string dst) -> double {
            if (!graph.count(src) || !graph.count(dst)) return -1.0;
            if (src == dst) return 1.0;
            unordered_set<string> visited;
            queue<pair<string, double>> q;
            q.push({src, 1.0});
            visited.insert(src);
            while (!q.empty()) {
                auto [node, prod] = q.front(); q.pop();
                if (node == dst) return prod;
                for (auto& [next, w] : graph[node]) {
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, prod * w});
                    }
                }
            }
            return -1.0;
        };
        vector<double> res;
        for (auto& q : queries) res.push_back(bfs(q[0], q[1]));
        return res;
    }
};
