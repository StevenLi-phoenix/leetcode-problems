// @leetcode id=1498 questionId=1621 slug=number-of-subsequences-that-satisfy-the-given-sum-condition lang=cpp site=leetcode.com title="Number of Subsequences That Satisfy the Given Sum Condition"
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const long long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        long long total = 0;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            if (nums[lo] + nums[hi] > target) {
                hi--;
            } else {
                total = (total + pow2[hi - lo]) % MOD;
                lo++;
            }
        }
        return (int)total;
    }
};
