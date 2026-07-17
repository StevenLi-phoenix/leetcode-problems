// @leetcode id=3883 questionId=4259 slug=count-non-decreasing-arrays-with-given-digit-sums lang=cpp site=leetcode.com title="Count Non Decreasing Arrays With Given Digit Sums"
class Solution {
public:
    int countArrays(vector<int>& digitSum) {
        const long long MOD = 1e9 + 7;
        const int MAXV = 5000;

        vector<vector<int>> bySum(51);
        for (int x = 0; x <= MAXV; x++) {
            int s = 0, t = x;
            while (t > 0) { s += t % 10; t /= 10; }
            if (s <= 50) bySum[s].push_back(x);
        }

        int n = digitSum.size();
        vector<long long> dp(MAXV + 1, 0);

        if (digitSum[0] > 50 || bySum[digitSum[0]].empty()) return 0;
        for (int x : bySum[digitSum[0]]) dp[x] = 1;

        for (int i = 1; i < n; i++) {
            if (digitSum[i] > 50 || bySum[digitSum[i]].empty()) return 0;

            vector<long long> prefix(MAXV + 1, 0);
            prefix[0] = dp[0];
            for (int x = 1; x <= MAXV; x++) prefix[x] = (prefix[x - 1] + dp[x]) % MOD;

            vector<long long> ndp(MAXV + 1, 0);
            for (int x : bySum[digitSum[i]]) ndp[x] = prefix[x];
            dp = ndp;
        }

        long long answer = 0;
        for (int x = 0; x <= MAXV; x++) answer = (answer + dp[x]) % MOD;
        return (int)answer;
    }
};
