// @leetcode id=2461 questionId=2552 slug=maximum-sum-of-distinct-subarrays-with-length-k lang=cpp site=leetcode.com title="Maximum Sum of Distinct Subarrays With Length K"
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        long long sum = 0, best = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            count[nums[i]]++;

            if (i >= k) {
                sum -= nums[i - k];
                count[nums[i - k]]--;
                if (count[nums[i - k]] == 0) count.erase(nums[i - k]);
            }

            if (i >= k - 1 && (int)count.size() == k) {
                best = max(best, sum);
            }
        }
        return best;
    }
};
