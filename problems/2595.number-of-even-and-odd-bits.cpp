// @leetcode id=2595 questionId=2659 slug=number-of-even-and-odd-bits lang=cpp site=leetcode.com title="Number of Even and Odd Bits"
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        int idx = 0;
        while (n > 0) {
            if (n & 1) {
                if (idx % 2 == 0) even++;
                else odd++;
            }
            n >>= 1;
            idx++;
        }
        return {even, odd};
    }
};
