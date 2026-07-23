// @leetcode id=3178 questionId=3450 slug=find-the-child-who-has-the-ball-after-k-seconds lang=cpp site=leetcode.com title="Find the Child Who Has the Ball After K Seconds"
class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycle = 2 * (n - 1);
        int pos = k % cycle;
        return pos < n - 1 ? pos : cycle - pos;
    }
};
