// @leetcode id=397 questionId=397 slug=integer-replacement lang=cpp site=leetcode.com title="Integer Replacement"
class Solution {
public:
    int integerReplacement(int n) {
        long long x = n; // n+1 can overflow a 32-bit int when n == INT_MAX
        int steps = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x /= 2;
            } else if (x == 3 || x % 4 == 1) {
                x--;
            } else {
                x++;
            }
            steps++;
        }
        return steps;
    }
};
