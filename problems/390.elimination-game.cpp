// @leetcode id=390 questionId=390 slug=elimination-game lang=cpp site=leetcode.com title="Elimination Game"
class Solution {
public:
    int lastRemaining(int n) {
        long long head = 1, step = 1;
        int remaining = n;
        bool leftToRight = true;
        while (remaining > 1) {
            // The head only moves when eliminating from the left, or when
            // eliminating from the right with an odd count (which also removes
            // the current head).
            if (leftToRight || remaining % 2 == 1) head += step;
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        return (int)head;
    }
};
