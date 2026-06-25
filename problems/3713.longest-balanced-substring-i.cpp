// @leetcode id=3713 questionId=4055 slug=longest-balanced-substring-i lang=cpp site=leetcode.com title="Longest Balanced Substring I"
class Solution {
public:
int longestBalanced(string s) {
int n = s.size();
int ans = 0;
for (int i = 0; i < n; i++) {
int freq[26] = {};
for (int j = i; j < n; j++) {
freq[s[j] - 'a']++;
int mx = 0, mn = INT_MAX;
int distinct = 0;
for (int k = 0; k < 26; k++) {
if (freq[k] > 0) {
distinct++;
mx = max(mx, freq[k]);
mn = min(mn, freq[k]);
}
}
if (mx == mn && distinct > 0) {
ans = max(ans, j - i + 1);
}
}
}
return ans;
}
};
