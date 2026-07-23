// @leetcode id=3994 questionId=4335 slug=minimum-adjacent-swaps-to-partition-array lang=cpp site=leetcode.com title="Minimum Adjacent Swaps to Partition Array"
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long count0 = 0, count1 = 0, count2 = 0, total = 0;
        for (int x : nums) {
            int cat = (x < a) ? 0 : (x <= b) ? 1 : 2;
            if (cat == 0) {
                total = (total + count1 + count2) % MOD;
                count0++;
            } else if (cat == 1) {
                total = (total + count2) % MOD;
                count1++;
            } else {
                count2++;
            }
        }
        return (int)(total % MOD);
    }
};
