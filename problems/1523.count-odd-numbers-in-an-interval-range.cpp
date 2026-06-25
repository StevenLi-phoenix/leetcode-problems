// @leetcode id=1523 questionId=1630 slug=count-odd-numbers-in-an-interval-range lang=cpp site=leetcode.com title="Count Odd Numbers in an Interval Range"
class Solution {
public:
    int countOdds(int low, int high) {
        // Count odds from 0 to n = (n+1)/2
        // Count odds from low to high = countTo(high) - countTo(low-1)
        auto countTo = [](int n) { return (n + 1) / 2; };
        return countTo(high) - countTo(low - 1);
    }
};
