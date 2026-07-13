// @leetcode id=1742 questionId=1844 slug=maximum-number-of-balls-in-a-box lang=cpp site=leetcode.com title="Maximum Number of Balls in a Box"
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int best = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, t = i;
            while (t > 0) {
                sum += t % 10;
                t /= 10;
            }
            best = max(best, ++count[sum]);
        }
        return best;
    }
};
