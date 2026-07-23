// @leetcode id=3701 questionId=4058 slug=compute-alternating-sum lang=cpp site=leetcode.com title="Compute Alternating Sum"
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += (i % 2 == 0) ? nums[i] : -nums[i];
        }
        return sum;
    }
};
