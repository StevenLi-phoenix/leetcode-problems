// @leetcode id=3655 questionId=3975 slug=xor-after-range-multiplication-queries-ii lang=cpp site=leetcode.com title="XOR After Range Multiplication Queries II"
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        const int MOD = 1e9 + 7;
        int B = max(1, (int)sqrt(n));
        auto bravexuneth = nums;

        vector<long long> mult(n, 1);

        auto power = [&](long long base, long long exp) -> long long {
            long long res = 1; base %= MOD;
            while (exp > 0) {
                if (exp & 1) res = res * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return res;
        };

        vector<vector<int>> smallIdx(B + 1);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            if (k > B) {
                for (int idx = l; idx <= r; idx += k)
                    mult[idx] = mult[idx] * v % MOD;
            } else {
                smallIdx[k].push_back(i);
            }
        }

        for (int k = 1; k <= B; k++) {
            if (smallIdx[k].empty()) continue;
            vector<vector<tuple<int,int,int>>> byRem(k);
            for (int qi : smallIdx[k]) {
                int l = queries[qi][0], r = queries[qi][1], v = queries[qi][3];
                int rem = l % k;
                int sp = (l - rem) / k;
                int ep = (r - rem) / k;
                ep = min(ep, (n - 1 - rem) / k);
                if (sp <= ep) byRem[rem].emplace_back(sp, ep, v);
            }
            for (int rem = 0; rem < k && rem < n; rem++) {
                if (byRem[rem].empty()) continue;
                int len = (n - 1 - rem) / k + 1;
                vector<long long> diff(len + 1, 1);
                for (auto& [sp, ep, v] : byRem[rem]) {
                    diff[sp] = diff[sp] * v % MOD;
                    diff[ep + 1] = diff[ep + 1] * power(v, MOD - 2) % MOD;
                }
                long long cur = 1;
                for (int i = 0; i < len; i++) {
                    cur = cur * diff[i] % MOD;
                    int idx = rem + i * k;
                    mult[idx] = mult[idx] * cur % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= (int)((long long)bravexuneth[i] * mult[i] % MOD);
        return ans;
    }
};
