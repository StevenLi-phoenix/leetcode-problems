// @leetcode id=2973 questionId=3218 slug=find-number-of-coins-to-place-in-tree-nodes lang=cpp site=leetcode.com title="Find Number of Coins to Place in Tree Nodes"
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> cost_;
    vector<long long> coin;

    void insertTop(vector<long long>& arr, long long v) {
        arr.push_back(v);
        sort(arr.rbegin(), arr.rend());
        if (arr.size() > 3) arr.pop_back();
    }

    void insertBot(vector<long long>& arr, long long v) {
        arr.push_back(v);
        sort(arr.begin(), arr.end());
        if (arr.size() > 2) arr.pop_back();
    }

    pair<int, pair<vector<long long>, vector<long long>>> dfs(int u, int parent) {
        vector<long long> topArr, botArr;
        insertTop(topArr, cost_[u]);
        insertBot(botArr, cost_[u]);
        int size = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;
            auto [childSize, childArrs] = dfs(v, u);
            size += childSize;
            for (long long x : childArrs.first) insertTop(topArr, x);
            for (long long x : childArrs.second) insertBot(botArr, x);
        }

        if (size < 3) {
            coin[u] = 1;
        } else {
            long long best = LLONG_MIN;
            if (topArr.size() >= 3) best = max(best, topArr[0] * topArr[1] * topArr[2]);
            if (botArr.size() >= 2 && topArr.size() >= 1) best = max(best, botArr[0] * botArr[1] * topArr[0]);
            coin[u] = max(0LL, best);
        }

        return {size, {topArr, botArr}};
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        cost_ = cost;
        coin.assign(n, 0);

        dfs(0, -1);

        return coin;
    }
};
