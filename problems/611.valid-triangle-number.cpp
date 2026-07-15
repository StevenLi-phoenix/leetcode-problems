// @leetcode id=611 questionId=611 slug=valid-triangle-number lang=cpp site=leetcode.com title="Valid Triangle Number"
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int k = n - 1; k >= 2; k--) {
            int lo = 0, hi = k - 1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] > nums[k]) {
                    count += hi - lo;
                    hi--;
                } else {
                    lo++;
                }
            }
        }
        return count;
    }
};
