// @leetcode id=2789 questionId=2872 slug=largest-element-in-an-array-after-merge-operations lang=cpp site=leetcode.com title="Largest Element in an Array after Merge Operations"
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long merged = nums[n - 1];
        long long best = merged;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= merged) {
                merged += nums[i];
            } else {
                merged = nums[i];
            }
            best = max(best, merged);
        }
        return best;
    }
};
