// @leetcode id=2579 questionId=2649 slug=count-total-number-of-colored-cells lang=cpp site=leetcode.com title="Count Total Number of Colored Cells"
class Solution {
public:
    long long coloredCells(int n) {
        return 2LL * n * n - 2LL * n + 1;
    }
};
