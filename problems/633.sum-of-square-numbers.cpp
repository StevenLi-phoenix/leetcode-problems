// @leetcode id=633 questionId=633 slug=sum-of-square-numbers lang=cpp site=leetcode.com title="Sum of Square Numbers"
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = (long long)sqrt((double)c);
        while (a <= b) {
            long long sum = a * a + b * b;
            if (sum == c) return true;
            if (sum < c) a++;
            else b--;
        }
        return false;
    }
};
