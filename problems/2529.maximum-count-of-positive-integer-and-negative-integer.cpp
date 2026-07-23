// @leetcode id=2529 questionId=2614 slug=maximum-count-of-positive-integer-and-negative-integer lang=cpp site=leetcode.com title="Maximum Count of Positive Integer and Negative Integer"
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(neg, pos);
    }
};
