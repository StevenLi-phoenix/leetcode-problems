// @leetcode id=868 questionId=899 slug=binary-gap lang=cpp site=leetcode.com title="Binary Gap"
class Solution {
public:
int binaryGap(int n) {
int ans = 0, last = -1;
for (int i = 0; i < 32; i++) {
if ((n >> i) & 1) {
if (last >= 0) ans = max(ans, i - last);
last = i;
}
}
return ans;
}
};
