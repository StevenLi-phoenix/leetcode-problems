// @leetcode id=2293 questionId=2386 slug=min-max-game lang=cpp site=leetcode.com title="Min Max Game"
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            int n = nums.size();
            vector<int> newNums(n / 2);
            for (int i = 0; i < n / 2; i++) {
                newNums[i] = (i % 2 == 0) ? min(nums[2 * i], nums[2 * i + 1])
                                          : max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = newNums;
        }
        return nums[0];
    }
};
