// @leetcode id=3689 questionId=4005 slug=maximum-total-subarray-value-i lang=cpp site=leetcode.com title="Maximum Total Subarray Value I"
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxVal = *max_element(nums.begin(), nums.end());
        long long minVal = *min_element(nums.begin(), nums.end());
        return (long long)k * (maxVal - minVal);
    }
};
