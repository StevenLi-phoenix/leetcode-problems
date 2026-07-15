// @leetcode id=2134 questionId=2255 slug=minimum-swaps-to-group-all-1s-together-ii lang=cpp site=leetcode.com title="Minimum Swaps to Group All 1's Together II"
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) ones += x;
        if (ones == 0 || ones == n) return 0;

        int windowOnes = 0;
        for (int i = 0; i < ones; i++) windowOnes += nums[i];
        int maxOnes = windowOnes;
        for (int i = 1; i < n; i++) {
            int outIdx = i - 1;
            int inIdx = (i + ones - 1) % n;
            windowOnes -= nums[outIdx];
            windowOnes += nums[inIdx];
            maxOnes = max(maxOnes, windowOnes);
        }
        return ones - maxOnes;
    }
};
