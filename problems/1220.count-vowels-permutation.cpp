// @leetcode id=1220 questionId=1332 slug=count-vowels-permutation lang=cpp site=leetcode.com title="Count Vowels Permutation"
class Solution {
public:
    int countVowelPermutation(int n) {
        const long long MOD = 1000000007;
        // 0=a,1=e,2=i,3=o,4=u
        vector<long long> dp(5, 1);

        for (int step = 1; step < n; step++) {
            vector<long long> next(5, 0);
            next[0] = (dp[1] + dp[2] + dp[4]) % MOD; // a follows e,i,u
            next[1] = (dp[0] + dp[2]) % MOD;         // e follows a,i
            next[2] = (dp[1] + dp[3]) % MOD;         // i follows e,o
            next[3] = dp[2];                          // o follows i
            next[4] = (dp[2] + dp[3]) % MOD;         // u follows i,o
            dp = next;
        }

        long long answer = 0;
        for (long long v : dp) answer = (answer + v) % MOD;
        return (int)answer;
    }
};
