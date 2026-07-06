// @leetcode id=1006 questionId=1048 slug=clumsy-factorial lang=cpp site=leetcode.com title="Clumsy Factorial"
class Solution {
public:
    int clumsy(int n) {
        vector<int> stack;
        stack.push_back(n);
        int num = n - 1;
        int op = 0; // 0=*, 1=/, 2=+, 3=-

        while (num > 0) {
            if (op == 0) {
                stack.back() *= num;
            } else if (op == 1) {
                stack.back() /= num;
            } else if (op == 2) {
                stack.push_back(num);
            } else {
                stack.push_back(-num);
            }
            op = (op + 1) % 4;
            --num;
        }

        int total = 0;
        for (int v : stack) total += v;
        return total;
    }
};
