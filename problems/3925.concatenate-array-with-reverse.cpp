// @leetcode id=3925 questionId=4299 slug=concatenate-array-with-reverse lang=cpp site=leetcode.com title="Concatenate Array With Reverse"
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[n - i - 1];
        }

        return ans;
    }
};
