// @leetcode id=2549 questionId=2679 slug=count-distinct-numbers-on-board lang=cpp site=leetcode.com title="Count Distinct Numbers on Board"
class Solution {
public:
    int distinctIntegers(int n) {
        return (n == 1) ? 1 : (n - 1);
    }
};
