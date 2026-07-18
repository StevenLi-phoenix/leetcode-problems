// @leetcode id=891 questionId=927 slug=sum-of-subsequence-widths lang=cpp site=leetcode.com title="Sum of Subsequence Widths"
class Solution {
public:
    static const long long MOD = 1000000007;

    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> pow2(n, 1);
        for (int i = 1; i < n; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long coeff = (pow2[i] - pow2[n - 1 - i] + MOD) % MOD;
            ans = (ans + coeff * (nums[i] % MOD)) % MOD;
        }

        return (int)ans;
    }
};
