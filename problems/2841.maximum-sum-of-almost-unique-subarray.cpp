// @leetcode id=2841 questionId=2954 slug=maximum-sum-of-almost-unique-subarray lang=cpp site=leetcode.com title="Maximum Sum of Almost Unique Subarray"
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
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

            if (i >= k - 1 && (int)count.size() >= m) {
                best = max(best, sum);
            }
        }
        return best;
    }
};
