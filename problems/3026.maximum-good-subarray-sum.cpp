// @leetcode id=3026 questionId=3265 slug=maximum-good-subarray-sum lang=cpp site=leetcode.com title="Maximum Good Subarray Sum"
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> minPrefix;
        long long prefix = 0;
        long long maxSum = LLONG_MIN;

        for (int val : nums) {
            auto it1 = minPrefix.find((long long)val - k);
            if (it1 != minPrefix.end()) {
                maxSum = max(maxSum, prefix + val - it1->second);
            }
            auto it2 = minPrefix.find((long long)val + k);
            if (it2 != minPrefix.end()) {
                maxSum = max(maxSum, prefix + val - it2->second);
            }

            auto it = minPrefix.find(val);
            if (it == minPrefix.end() || prefix < it->second) {
                minPrefix[val] = prefix;
            }
            prefix += val;
        }
        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};
