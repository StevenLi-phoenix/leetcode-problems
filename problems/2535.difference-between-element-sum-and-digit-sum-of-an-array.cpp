// @leetcode id=2535 questionId=2624 slug=difference-between-element-sum-and-digit-sum-of-an-array lang=cpp site=leetcode.com title="Difference Between Element Sum and Digit Sum of an Array"
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elemSum = 0, digitSum = 0;
        for (int n : nums) {
            elemSum += n;
            int tmp = n;
            while (tmp > 0) {
                digitSum += tmp % 10;
                tmp /= 10;
            }
        }
        return abs(elemSum - digitSum);
    }
};
