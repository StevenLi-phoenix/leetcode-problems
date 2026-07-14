// @leetcode id=2419 questionId=2503 slug=longest-subarray-with-maximum-bitwise-and lang=cpp site=leetcode.com title="Longest Subarray With Maximum Bitwise AND"
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int best = 0, cur = 0;
        for (int v : nums) {
            cur = (v == maxVal) ? cur + 1 : 0;
            best = max(best, cur);
        }
        return best;
    }
};
