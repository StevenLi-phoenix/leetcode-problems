// @leetcode id=696 questionId=696 slug=count-binary-substrings lang=cpp site=leetcode.com title="Count Binary Substrings"
class Solution {
public:
int countBinarySubstrings(string s) {
int prev = 0, curr = 1, ans = 0;
for (int i = 1; i < (int)s.size(); i++) {
if (s[i] == s[i-1]) {
curr++;
} else {
ans += min(prev, curr);
prev = curr;
curr = 1;
}
}
ans += min(prev, curr);
return ans;
}
};
