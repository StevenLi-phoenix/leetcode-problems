// @leetcode id=2646 questionId=2739 slug=minimize-the-total-price-of-the-trips lang=cpp site=leetcode.com title="Minimize the Total Price of the Trips"
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> cnt;
    vector<int> price_;

    bool findPath(int node, int parent, int target, vector<int>& path) {
        path.push_back(node);
        if (node == target) return true;
        for (int next : adj[node]) {
            if (next != parent && findPath(next, node, target, path)) return true;
        }
        path.pop_back();
        return false;
    }

    pair<int,int> dfs(int node, int parent) {
        int withNode = cnt[node] * price_[node] / 2;
        int withoutNode = 0;
        for (int next : adj[node]) {
            if (next != parent) {
                auto [w, wo] = dfs(next, node);
                withNode += wo;
                withoutNode += max(w, wo);
            }
        }
        return {withNode, withoutNode};
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        cnt.assign(n, 0);
        price_ = price;

        for (auto& t : trips) {
            vector<int> path;
            findPath(t[0], -1, t[1], path);
            for (int node : path) cnt[node]++;
        }

        long long baseCost = 0;
        for (int i = 0; i < n; i++) baseCost += (long long)cnt[i] * price[i];

        auto [withRoot, withoutRoot] = dfs(0, -1);
        long long savings = max(withRoot, withoutRoot);

        return (int)(baseCost - savings);
    }
};
