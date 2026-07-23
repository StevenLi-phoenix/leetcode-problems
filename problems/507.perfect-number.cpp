// @leetcode id=507 questionId=507 slug=perfect-number lang=cpp site=leetcode.com title="Perfect Number"
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;

        long long sum = 1;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) sum += num / i;
            }
        }
        return sum == num;
    }
};
