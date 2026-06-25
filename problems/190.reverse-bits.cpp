// @leetcode id=190 questionId=190 slug=reverse-bits lang=cpp site=leetcode.com title="Reverse Bits"
class Solution {
public:
uint32_t reverseBits(uint32_t n) {
uint32_t result = 0;
for (int i = 0; i < 32; i++) {
result = (result << 1) | (n & 1);
n >>= 1;
}
return result;
}
};
