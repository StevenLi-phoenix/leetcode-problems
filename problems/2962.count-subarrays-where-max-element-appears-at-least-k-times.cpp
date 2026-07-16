// @leetcode id=2962 questionId=3213 slug=count-subarrays-where-max-element-appears-at-least-k-times lang=cpp site=leetcode.com title="Count Subarrays Where Max Element Appears at Least K Times"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        long long result = 0;
        int left = 0, count = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == maxVal) count++;
            while (count >= k) {
                if (nums[left] == maxVal) count--;
                left++;
            }
            result += left;
        }
        return result;
    }
};
