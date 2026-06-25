// @leetcode id=2413 questionId=2491 slug=smallest-even-multiple lang=cpp site=leetcode.com title="Smallest Even Multiple"
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n % 2 == 0) ? n : 2 * n;
    }
};
