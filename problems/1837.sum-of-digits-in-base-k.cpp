// @leetcode id=1837 questionId=1965 slug=sum-of-digits-in-base-k lang=cpp site=leetcode.com title="Sum of Digits in Base K"
class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while (n > 0) {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};
