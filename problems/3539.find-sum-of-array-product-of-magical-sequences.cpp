// @leetcode id=3539 questionId=3851 slug=find-sum-of-array-product-of-magical-sequences lang=cpp site=leetcode.com title="Find Sum of Array Product of Magical Sequences"
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        // Choosing an ordered sequence reduces to choosing multiplicities
        // c_i (sum = m); the sequence's bit sum is formed by ripple-carry
        // addition of c_i*2^i, so DP over bit positions tracking
        // (elements used, carry, popcount so far). The multinomial
        // m!/prod(c_i!) is built by dividing by c_i! per step and
        // multiplying by m! at the end.
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> fact(m + 1), invFact(m + 1);
        fact[0] = 1;
        for (int i = 1; i <= m; i++) fact[i] = fact[i - 1] * i % MOD;
        auto power = [&](long long b, long long e) {
            long long r = 1;
            b %= MOD;
            while (e > 0) {
                if (e & 1) r = r * b % MOD;
                b = b * b % MOD;
                e >>= 1;
            }
            return r;
        };
        invFact[m] = power(fact[m], MOD - 2);
        for (int i = m; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

        vector<vector<long long>> powNums(n, vector<long long>(m + 1));
        for (int i = 0; i < n; i++) {
            powNums[i][0] = 1;
            for (int c = 1; c <= m; c++) powNums[i][c] = powNums[i][c - 1] * nums[i] % MOD;
        }

        int maxBit = n + 10;
        // dp[usedCount][carry][pc]
        vector<vector<vector<long long>>> dp(
            m + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        dp[0][0][0] = 1;

        for (int bit = 0; bit < maxBit; bit++) {
            vector<vector<vector<long long>>> newDp(
                m + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
            for (int used = 0; used <= m; used++) {
                for (int carry = 0; carry <= m; carry++) {
                    for (int pc = 0; pc <= k; pc++) {
                        long long val = dp[used][carry][pc];
                        if (val == 0) continue;
                        int maxC = (bit < n) ? (m - used) : 0;
                        for (int c = 0; c <= maxC; c++) {
                            int total = c + carry;
                            int bitOut = total & 1;
                            int carryOut = total >> 1;
                            int newPc = pc + bitOut;
                            if (newPc > k || carryOut > m) continue;
                            long long weight = (bit < n) ? (powNums[bit][c] * invFact[c] % MOD) : 1;
                            long long contribution = val * weight % MOD;
                            newDp[used + c][carryOut][newPc] =
                                (newDp[used + c][carryOut][newPc] + contribution) % MOD;
                        }
                    }
                }
            }
            dp = move(newDp);
        }

        long long ans = fact[m] * dp[m][0][k] % MOD;
        return (int)ans;
    }
};
