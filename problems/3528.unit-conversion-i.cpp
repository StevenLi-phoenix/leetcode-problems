// @leetcode id=3528 questionId=3729 slug=unit-conversion-i lang=cpp site=leetcode.com title="Unit Conversion I"
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const long long MOD = 1e9 + 7;
        int n = conversions.size() + 1;
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& c : conversions) {
            adj[c[0]].push_back({c[1], c[2]});
        }

        vector<long long> result(n, -1);
        result[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, factor] : adj[u]) {
                result[v] = (result[u] * factor) % MOD;
                q.push(v);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
