// @leetcode id=1916 questionId=1313 slug=count-ways-to-build-rooms-in-an-ant-colony lang=cpp site=leetcode.com title="Count Ways to Build Rooms in an Ant Colony"
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = power(fact[n], MOD - 2, MOD);
        for (int i = n; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[prevRoom[i]].push_back(i);

        vector<int> size(n, 0);
        vector<long long> ways(n, 1);

        vector<int> order;
        order.reserve(n);
        vector<int> stack = {0};
        while (!stack.empty()) {
            int u = stack.back(); stack.pop_back();
            order.push_back(u);
            for (int c : children[u]) stack.push_back(c);
        }

        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            size[u] = 1;
            long long w = fact[0];
            long long denom = 1;
            long long childProduct = 1;
            for (int c : children[u]) {
                size[u] += size[c];
                denom = denom * invFact[size[c]] % MOD;
                childProduct = childProduct * ways[c] % MOD;
            }
            w = fact[size[u] - 1] * denom % MOD;
            ways[u] = w * childProduct % MOD;
        }

        return (int)ways[0];
    }
};
