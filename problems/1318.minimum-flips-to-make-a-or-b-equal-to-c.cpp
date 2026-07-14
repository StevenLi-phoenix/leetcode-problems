// @leetcode id=1318 questionId=1441 slug=minimum-flips-to-make-a-or-b-equal-to-c lang=cpp site=leetcode.com title="Minimum Flips to Make a OR b Equal to c"
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            if (bitC == 0) {
                flips += bitA + bitB;
            } else {
                if (bitA == 0 && bitB == 0) flips++;
            }
        }
        return flips;
    }
};
