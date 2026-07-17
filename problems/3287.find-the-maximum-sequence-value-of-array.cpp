// @leetcode id=3287 questionId=3575 slug=find-the-maximum-sequence-value-of-array lang=cpp site=leetcode.com title="Find the Maximum Sequence Value of Array"
class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();

        // leftPossible[i] = bitset<128> of achievable OR values choosing exactly k elements from nums[0..i-1]
        vector<bitset<128>> leftPossible(n + 1);
        {
            vector<bitset<128>> dp(k + 1);
            dp[0][0] = 1;
            leftPossible[0] = dp[k];
            for (int i = 1; i <= n; i++) {
                int x = nums[i - 1];
                for (int c = k; c >= 1; c--) {
                    bitset<128> add;
                    for (int v = 0; v < 128; v++) {
                        if (dp[c - 1][v]) add[v | x] = 1;
                    }
                    dp[c] |= add;
                }
                leftPossible[i] = dp[k];
            }
        }

        // rightPossible[i] = bitset<128> of achievable OR values choosing exactly k elements from nums[i..n-1]
        vector<bitset<128>> rightPossible(n + 1);
        {
            vector<bitset<128>> dp(k + 1);
            dp[0][0] = 1;
            rightPossible[n] = dp[k];
            for (int i = n - 1; i >= 0; i--) {
                int x = nums[i];
                for (int c = k; c >= 1; c--) {
                    bitset<128> add;
                    for (int v = 0; v < 128; v++) {
                        if (dp[c - 1][v]) add[v | x] = 1;
                    }
                    dp[c] |= add;
                }
                rightPossible[i] = dp[k];
            }
        }

        int best = 0;
        for (int m = k; m <= n - k; m++) {
            auto& L = leftPossible[m];
            auto& R = rightPossible[m];
            for (int a = 0; a < 128; a++) {
                if (!L[a]) continue;
                for (int b = 0; b < 128; b++) {
                    if (!R[b]) continue;
                    best = max(best, a ^ b);
                }
            }
        }

        return best;
    }
};
