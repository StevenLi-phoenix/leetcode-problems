// @leetcode id=1493 questionId=1586 slug=longest-subarray-of-1s-after-deleting-one-element lang=cpp site=leetcode.com title="Longest Subarray of 1's After Deleting One Element"
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeros = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > 1) {
                if (nums[left++] == 0) zeros--;
            }
            // Window size is right - left + 1, but we delete one element
            ans = max(ans, right - left); // right - left + 1 - 1 = right - left
        }
        return ans;
    }
};
