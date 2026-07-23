// @leetcode id=1137 questionId=1236 slug=n-th-tribonacci-number lang=cpp site=leetcode.com title="N-th Tribonacci Number"
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        long long a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            long long next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return (int)c;
    }
};
