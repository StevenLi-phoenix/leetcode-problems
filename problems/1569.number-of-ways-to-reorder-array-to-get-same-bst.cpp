// @leetcode id=1569 questionId=1692 slug=number-of-ways-to-reorder-array-to-get-same-bst lang=cpp site=leetcode.com title="Number of Ways to Reorder Array to Get Same BST"
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long MOD = 1e9 + 7;

        int n = nums.size();
        vector<long long> fact(n), inv_fact(n);

        auto modpow = [&](long long a, long long b) -> long long {
            long long res = 1;
            a %= MOD;
            while (b > 0) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[n - 1] = modpow(fact[n - 1], MOD - 2);
        for (int i = n - 2; i >= 0; i--) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }

        auto nCr = [&](int n, int r) -> long long {
            if (r < 0 || r > n) return 0;
            return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
        };

        function<long long(vector<int>&)> solve = [&](vector<int>& arr) -> long long {
            if (arr.size() <= 1) return 1;

            int root = arr[0];
            vector<int> left, right;

            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] < root) {
                    left.push_back(arr[i]);
                } else {
                    right.push_back(arr[i]);
                }
            }

            long long ways = nCr(left.size() + right.size(), left.size());
            ways = ways * solve(left) % MOD;
            ways = ways * solve(right) % MOD;

            return ways;
        };

        long long result = solve(nums);
        return (result - 1 + MOD) % MOD;
    }
};
