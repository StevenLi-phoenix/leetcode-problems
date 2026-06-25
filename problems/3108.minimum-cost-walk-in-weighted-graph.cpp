// @leetcode id=3108 questionId=3348 slug=minimum-cost-walk-in-weighted-graph lang=cpp site=leetcode.com title="Minimum Cost Walk in Weighted Graph"
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n), rank_(n, 0), cost(n, -1);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        
        auto unite = [&](int x, int y, int w) {
            int px = find(x), py = find(y);
            if (px == py) {
                cost[px] &= w;
                return;
            }
            if (rank_[px] < rank_[py]) swap(px, py);
            parent[py] = px;
            if (rank_[px] == rank_[py]) rank_[px]++;
            cost[px] = (cost[px] & cost[py] & w);
        };
        
        for (auto& e : edges) {
            unite(e[0], e[1], e[2]);
        }
        
        vector<int> ans;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (s == t) { ans.push_back(0); continue; }
            int ps = find(s), pt = find(t);
            if (ps != pt) { ans.push_back(-1); continue; }
            ans.push_back(cost[ps]);
        }
        return ans;
    }
};
