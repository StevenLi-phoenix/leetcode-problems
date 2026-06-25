// @leetcode id=3315 questionId=3611 slug=construct-the-minimum-bitwise-array-ii lang=cpp site=leetcode.com title="Construct the Minimum Bitwise Array II"
class Solution {
public:
vector<int> minBitwiseArray(vector<int>& nums) {
vector<int> ans;
for (long long p : nums) {
if (p == 2) { ans.push_back(-1); continue; }
int res = -1;
for (int k = 30; k >= 0; k--) {
if (!((p >> k) & 1)) continue;
long long mask = (1LL << k) - 1;
if ((p & mask) == mask) {
res = (int)(p ^ (1LL << k));
break;
}
}
ans.push_back(res);
}
return ans;
}
};
