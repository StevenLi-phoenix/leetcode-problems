// @leetcode id=3099 questionId=3371 slug=harshad-number lang=cpp site=leetcode.com title="Harshad Number"
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        for (int t = x; t > 0; t /= 10) sum += t % 10;
        return (x % sum == 0) ? sum : -1;
    }
};
