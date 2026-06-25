// @leetcode id=1200 questionId=1306 slug=minimum-absolute-difference lang=cpp site=leetcode.com title="Minimum Absolute Difference"
class Solution {
public:
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
sort(arr.begin(), arr.end());
int minDiff = INT_MAX;
for (int i = 1; i < (int)arr.size(); i++)
minDiff = min(minDiff, arr[i]-arr[i-1]);
vector<vector<int>> res;
for (int i = 1; i < (int)arr.size(); i++)
if (arr[i]-arr[i-1] == minDiff)
res.push_back({arr[i-1], arr[i]});
return res;
}
};
