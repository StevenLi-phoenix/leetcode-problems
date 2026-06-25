// @leetcode id=693 questionId=693 slug=binary-number-with-alternating-bits lang=cpp site=leetcode.com title="Binary Number with Alternating Bits"
class Solution {
public:
bool hasAlternatingBits(int n) {
int prev = n & 1;
n >>= 1;
while (n > 0) {
int curr = n & 1;
if (curr == prev) return false;
prev = curr;
n >>= 1;
}
return true;
}
};
