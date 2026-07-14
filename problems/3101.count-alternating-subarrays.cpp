// @leetcode id=3101 questionId=3374 slug=count-alternating-subarrays lang=cpp site=leetcode.com title="Count Alternating Subarrays"
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long total = 0;
        long long runLen = 1;
        for (int i = 1; i <= (int)nums.size(); i++) {
            if (i < (int)nums.size() && nums[i] != nums[i - 1]) {
                runLen++;
            } else {
                total += runLen * (runLen + 1) / 2;
                runLen = 1;
            }
        }
        return total;
    }
};
