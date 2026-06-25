// @leetcode id=3314 questionId=3605 slug=construct-the-minimum-bitwise-array-i lang=cpp site=leetcode.com title="Construct the Minimum Bitwise Array I"
class Solution {
public:
vector<int> minBitwiseArray(vector<int>& nums) {
vector<int> ans;
for (int p : nums) {
if (p == 2) { ans.push_back(-1); continue; }
int res = -1;
for (int x = 0; x < p; x++) {
if ((x | (x+1)) == p) { res = x; break; }
}
ans.push_back(res);
}
return ans;
}
};
