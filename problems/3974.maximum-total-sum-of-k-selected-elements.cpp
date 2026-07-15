// @leetcode id=3974 questionId=4348 slug=maximum-total-sum-of-k-selected-elements lang=cpp site=leetcode.com title="Maximum Total Sum of K Selected Elements"
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long total = 0;
        for (int i = 0; i < k; i++) {
            long long weight = max(1, mul - i);
            total += (long long)nums[i] * weight;
        }
        return total;
    }
};
