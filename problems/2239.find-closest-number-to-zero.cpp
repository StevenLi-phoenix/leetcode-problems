// @leetcode id=2239 questionId=2350 slug=find-closest-number-to-zero lang=cpp site=leetcode.com title="Find Closest Number to Zero"
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        for (int num : nums) {
            if (abs(num) < abs(closest) || (abs(num) == abs(closest) && num > closest)) {
                closest = num;
            }
        }
        return closest;
    }
};
