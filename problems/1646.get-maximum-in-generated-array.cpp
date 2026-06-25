// @leetcode id=1646 questionId=1769 slug=get-maximum-in-generated-array lang=cpp site=leetcode.com title="Get Maximum in Generated Array"
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> nums(n + 1);
        nums[0] = 0;
        nums[1] = 1;

        for (int i = 1; i <= n / 2; i++) {
            if (2 * i <= n) {
                nums[2 * i] = nums[i];
            }
            if (2 * i + 1 <= n) {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
            }
        }

        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }

        return maxVal;
    }
};
