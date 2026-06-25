// @leetcode id=2958 questionId=3225 slug=length-of-longest-subarray-with-at-most-k-frequency lang=cpp site=leetcode.com title="Length of Longest Subarray With at Most K Frequency"
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
