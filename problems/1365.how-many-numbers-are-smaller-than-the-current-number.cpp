// @leetcode id=1365 questionId=1482 slug=how-many-numbers-are-smaller-than-the-current-number lang=cpp site=leetcode.com title="How Many Numbers Are Smaller Than the Current Number"
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101] = {};
        for (int x : nums) count[x]++;
        int prefix[101] = {};
        for (int v = 1; v <= 100; v++) prefix[v] = prefix[v - 1] + count[v - 1];

        vector<int> ans(nums.size());
        for (int i = 0; i < (int)nums.size(); i++) ans[i] = prefix[nums[i]];
        return ans;
    }
};
