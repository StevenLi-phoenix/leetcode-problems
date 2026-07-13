// @leetcode id=3804 questionId=4129 slug=number-of-centered-subarrays lang=cpp site=leetcode.com title="Number of Centered Subarrays"
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                seen.insert(nums[j]);
                if (sum >= INT_MIN && sum <= INT_MAX && seen.count((int)sum)) count++;
            }
        }
        return count;
    }
};
