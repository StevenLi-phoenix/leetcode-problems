// @leetcode id=2996 questionId=3236 slug=smallest-missing-integer-greater-than-sequential-prefix-sum lang=cpp site=leetcode.com title="Smallest Missing Integer Greater Than Sequential Prefix Sum"
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int i = 1;
        while (i < n && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        unordered_set<int> present(nums.begin(), nums.end());
        while (present.count(sum)) sum++;
        return sum;
    }
};
