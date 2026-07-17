// @leetcode id=3351 questionId=3646 slug=sum-of-good-subsequences lang=cpp site=leetcode.com title="Sum of Good Subsequences"
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const long long MOD = 1000000007;
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<long long> cnt(maxVal + 3, 0), sum(maxVal + 3, 0);

        for (int x : nums) {
            long long prevCnt = (x - 1 >= 0 ? cnt[x - 1] : 0) + cnt[x + 1];
            long long prevSum = (x - 1 >= 0 ? sum[x - 1] : 0) + sum[x + 1];

            long long newCnt = (1 + prevCnt) % MOD;
            long long newSum = ((long long)x % MOD * newCnt % MOD + prevSum) % MOD;

            cnt[x] = (cnt[x] + newCnt) % MOD;
            sum[x] = (sum[x] + newSum) % MOD;
        }

        long long answer = 0;
        for (int v = 0; v <= maxVal; v++) answer = (answer + sum[v]) % MOD;

        return (int)answer;
    }
};
