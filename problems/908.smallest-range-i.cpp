// @leetcode id=908 questionId=944 slug=smallest-range-i lang=cpp site=leetcode.com title="Smallest Range I"
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return max(0, (mx - mn) - 2 * k);
    }
};
