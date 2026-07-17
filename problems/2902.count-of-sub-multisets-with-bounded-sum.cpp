// @leetcode id=2902 questionId=3091 slug=count-of-sub-multisets-with-bounded-sum lang=cpp site=leetcode.com title="Count of Sub-Multisets With Bounded Sum"
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const long long MOD = 1e9 + 7;
        map<int, int> freq;
        long long zeroCount = 0;

        for (int x : nums) {
            if (x == 0) zeroCount++;
            else freq[x]++;
        }

        int cap = r;
        vector<long long> dp(cap + 1, 0);
        dp[0] = 1;

        for (auto& [v, c] : freq) {
            vector<long long> ndp = dp;
            for (int s = v; s <= cap; s++) {
                ndp[s] = (ndp[s] + ndp[s - v]) % MOD;
                long long sub = ((long long)c + 1) * v;
                if (s - sub >= 0) ndp[s] = (ndp[s] - dp[s - sub] + MOD) % MOD;
            }
            dp = ndp;
        }

        long long answer = 0;
        for (int s = l; s <= r; s++) answer = (answer + dp[s]) % MOD;
        answer = answer * ((zeroCount + 1) % MOD) % MOD;

        return (int)answer;
    }
};
