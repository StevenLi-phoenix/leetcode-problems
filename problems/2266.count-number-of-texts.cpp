// @leetcode id=2266 questionId=2348 slug=count-number-of-texts lang=cpp site=leetcode.com title="Count Number of Texts"
class Solution {
public:
    int countTexts(string pressedKeys) {
        const long long MOD = 1e9 + 7;
        int n = pressedKeys.size();
        int i = 0;
        vector<long long> f = {1, 1, 2, 4};

        long long result = 1;
        while (i < n) {
            int j = i;
            while (j < n && pressedKeys[j] == pressedKeys[i]) j++;
            int len = j - i;
            int maxLetters = (pressedKeys[i] == '7' || pressedKeys[i] == '9') ? 4 : 3;

            vector<long long> dp(len + 1, 0);
            dp[0] = 1;
            for (int k = 1; k <= len; k++) {
                for (int m = 1; m <= maxLetters && m <= k; m++) {
                    dp[k] = (dp[k] + dp[k - m]) % MOD;
                }
            }
            result = (result * dp[len]) % MOD;
            i = j;
        }
        return (int)result;
    }
};
