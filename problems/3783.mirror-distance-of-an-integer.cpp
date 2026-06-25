// @leetcode id=3783 questionId=4168 slug=mirror-distance-of-an-integer lang=cpp site=leetcode.com title="Mirror Distance of an Integer"
class Solution {
public:
int mirrorDistance(int n) {
int rev = 0, tmp = n;
while (tmp > 0) {
rev = rev * 10 + tmp % 10;
tmp /= 10;
}
return abs(n - rev);
}
};
