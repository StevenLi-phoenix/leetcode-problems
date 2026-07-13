// @leetcode id=2681 questionId=2784 slug=power-of-heroes lang=cpp site=leetcode.com title="Power of Heroes"
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const long long MOD = 1'000'000'007;
        sort(nums.begin(), nums.end());

        // Fixing nums[i] (sorted) as the group's max, the min ranges over
        // any nums[j] with j<=i, and any subset of the elements strictly
        // between j and i may freely join (they don't affect max/min).
        // T tracks sum_{j<=i-1} nums[j] * 2^{(i-1)-j}, updated as
        // T = 2*T + nums[i] each step (classic "weighted by gap" trick).
        long long T = 0, ans = 0;
        for (int x : nums) {
            long long xm = x % MOD;
            long long contrib = (xm * xm % MOD) * ((T + xm) % MOD) % MOD;
            ans = (ans + contrib) % MOD;
            T = (2 * T + xm) % MOD;
        }
        return (int)ans;
    }
};
