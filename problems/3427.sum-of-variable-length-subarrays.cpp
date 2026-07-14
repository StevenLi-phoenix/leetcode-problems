// @leetcode id=3427 questionId=3731 slug=sum-of-variable-length-subarrays lang=cpp site=leetcode.com title="Sum of Variable Length Subarrays"
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        int total = 0;
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            total += prefix[i + 1] - prefix[start];
        }
        return total;
    }
};
