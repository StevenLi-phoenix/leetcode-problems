// @leetcode id=1438 questionId=1549 slug=longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit lang=cpp site=leetcode.com title="Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit"
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, max_len = 0;
        multiset<int> window;

        for (int right = 0; right < (int)nums.size(); right++) {
            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[left]));
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
