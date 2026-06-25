// @leetcode id=1292 questionId=1413 slug=maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold lang=cpp site=leetcode.com title="Maximum Side Length of a Square with Sum Less than or Equal to Threshold"
class Solution {
public:
int maxSideLength(vector<vector<int>>& mat, int threshold) {
int m = mat.size(), n = mat[0].size();
vector<vector<int>> pre(m+1, vector<int>(n+1, 0));
for (int i = 1; i <= m; i++)
for (int j = 1; j <= n; j++)
pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
int ans = 0;
for (int k = 1; k <= min(m,n); k++) {
bool found = false;
for (int i = k; i <= m && !found; i++) {
for (int j = k; j <= n && !found; j++) {
int s = pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k];
if (s <= threshold) { ans = k; found = true; }
}
}
if (!found) break;
}
return ans;
}
};
