// @leetcode id=3021 questionId=3279 slug=alice-and-bob-playing-flower-game lang=cpp site=leetcode.com title="Alice and Bob Playing Flower Game"
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long xOdd = (n + 1) / 2, xEven = n / 2;
        long long yOdd = (m + 1) / 2, yEven = m / 2;
        return xOdd * yEven + xEven * yOdd;
    }
};
