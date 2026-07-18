// @leetcode id=3022 questionId=3261 slug=minimize-or-of-remaining-elements-using-operations lang=cpp site=leetcode.com title="Minimize OR of Remaining Elements Using Operations"
class Solution {
public:
    bool check(vector<int>& nums, int mask, int k) {
        int groups = 0;
        int cur = -1;
        for (int x : nums) {
            cur &= x;
            if ((cur & mask) == 0) {
                groups++;
                cur = -1;
            }
        }
        int n = nums.size();
        int merges = n - groups;
        return merges <= k;
    }

    int minOrAfterOperations(vector<int>& nums, int k) {
        int zeroMask = 0;
        int ans = 0;
        for (int b = 29; b >= 0; b--) {
            int testMask = zeroMask | (1 << b);
            if (check(nums, testMask, k)) {
                zeroMask = testMask;
            } else {
                ans |= (1 << b);
            }
        }
        return ans;
    }
};
