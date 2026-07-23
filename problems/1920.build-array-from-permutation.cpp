// @leetcode id=1920 questionId=2048 slug=build-array-from-permutation lang=cpp site=leetcode.com title="Build Array from Permutation"
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
