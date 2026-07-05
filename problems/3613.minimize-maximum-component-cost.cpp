// @leetcode id=3613 questionId=3881 slug=minimize-maximum-component-cost lang=cpp site=leetcode.com title="Minimize Maximum Component Cost"
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int maxW = 0;
        for (auto& e : edges) maxW = max(maxW, e[2]);

        auto feasible = [&](int w) {
            vector<int> parent(n);
            iota(parent.begin(), parent.end(), 0);
            function<int(int)> find = [&](int x) {
                while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
                return x;
            };
            int components = n;
            for (auto& e : edges) {
                if (e[2] <= w) {
                    int ra = find(e[0]), rb = find(e[1]);
                    if (ra != rb) { parent[ra] = rb; --components; }
                }
            }
            return components <= k;
        };

        int lo = 0, hi = maxW;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
