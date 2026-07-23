// @leetcode id=2980 questionId=3246 slug=check-if-bitwise-or-has-trailing-zeros lang=cpp site=leetcode.com title="Check if Bitwise OR Has Trailing Zeros"
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenCount = 0;
        for (int x : nums) {
            if (x % 2 == 0) evenCount++;
        }
        return evenCount >= 2;
    }
};
