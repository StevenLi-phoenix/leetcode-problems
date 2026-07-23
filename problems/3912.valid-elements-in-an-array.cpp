// @leetcode id=3912 questionId=4290 slug=valid-elements-in-an-array lang=cpp site=leetcode.com title="Valid Elements in an Array"
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(n), maxRight(n);

        maxLeft[0] = INT_MIN;
        for (int i = 1; i < n; i++) maxLeft[i] = max(maxLeft[i - 1], nums[i - 1]);

        maxRight[n - 1] = INT_MIN;
        for (int i = n - 2; i >= 0; i--) maxRight[i] = max(maxRight[i + 1], nums[i + 1]);

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxLeft[i] || nums[i] > maxRight[i]) result.push_back(nums[i]);
        }
        return result;
    }
};
