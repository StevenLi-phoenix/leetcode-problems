// @leetcode id=754 questionId=755 slug=reach-a-number lang=cpp site=leetcode.com title="Reach a Number"
class Solution {
public:
    int reachNumber(int target) {
        long long t = abs((long long)target);
        long long n = 0, sum = 0;
        while (sum < t || (sum - t) % 2 != 0) {
            n++;
            sum += n;
        }
        return (int)n;
    }
};
