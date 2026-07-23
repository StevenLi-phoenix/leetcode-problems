// @leetcode id=2778 questionId=2844 slug=sum-of-squares-of-special-elements lang=cpp site=leetcode.com title="Sum of Squares of Special Elements "
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) sum += nums[i - 1] * nums[i - 1];
        }
        return sum;
    }
};
