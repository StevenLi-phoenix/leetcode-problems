// @leetcode id=2097 questionId=2201 slug=valid-arrangement-of-pairs lang=cpp site=leetcode.com title="Valid Arrangement of Pairs"
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> outdeg, indeg;
        for (auto& p : pairs) {
            adj[p[0]].push_back(p[1]);
            outdeg[p[0]]++;
            indeg[p[1]]++;
        }

        int start = pairs[0][0];
        for (auto& [node, out] : outdeg) {
            if (out - indeg[node] == 1) { start = node; break; }
        }

        unordered_map<int, size_t> ptr;
        vector<int> stack = {start};
        vector<int> circuit;

        while (!stack.empty()) {
            int v = stack.back();
            auto& edges = adj[v];
            size_t& p = ptr[v];
            if (p < edges.size()) {
                stack.push_back(edges[p++]);
            } else {
                circuit.push_back(v);
                stack.pop_back();
            }
        }
        reverse(circuit.begin(), circuit.end());

        vector<vector<int>> result;
        for (size_t i = 0; i + 1 < circuit.size(); i++) {
            result.push_back({circuit[i], circuit[i + 1]});
        }
        return result;
    }
};
