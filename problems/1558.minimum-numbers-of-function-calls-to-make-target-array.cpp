// @leetcode id=1558 questionId=1662 slug=minimum-numbers-of-function-calls-to-make-target-array lang=cpp site=leetcode.com title="Minimum Numbers of Function Calls to Make Target Array"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int addOps = 0, maxBits = 0;
        for (int v : nums) {
            addOps += __builtin_popcount(v);
            int bits = 0;
            while (v > 0) {
                bits++;
                v >>= 1;
            }
            maxBits = max(maxBits, bits);
        }
        int doubleOps = maxBits > 0 ? maxBits - 1 : 0;
        return addOps + doubleOps;
    }
};
