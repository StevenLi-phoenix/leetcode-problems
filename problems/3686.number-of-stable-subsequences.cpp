// @leetcode id=3686 questionId=4027 slug=number-of-stable-subsequences lang=cpp site=leetcode.com title="Number of Stable Subsequences"
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        long long e1 = 0, e2 = 0, o1 = 0, o2 = 0;

        for (int x : nums) {
            if (x % 2 == 0) {
                long long newE2 = e1;
                long long newE1 = (o1 + o2 + 1) % MOD;
                e2 = (e2 + newE2) % MOD;
                e1 = (e1 + newE1) % MOD;
            } else {
                long long newO2 = o1;
                long long newO1 = (e1 + e2 + 1) % MOD;
                o2 = (o2 + newO2) % MOD;
                o1 = (o1 + newO1) % MOD;
            }
        }

        return (int)((e1 + e2 + o1 + o2) % MOD);
    }
};
