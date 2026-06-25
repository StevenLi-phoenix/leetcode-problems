// @leetcode id=2615 questionId=2721 slug=sum-of-distances lang=cpp site=leetcode.com title="Sum of Distances"
class Solution {
public:
vector<long long> distance(vector<int>& nums) {
int n = nums.size();
vector<long long> ans(n, 0);
unordered_map<int, vector<int>> groups;
for (int i = 0; i < n; i++) {
groups[nums[i]].push_back(i);
}
for (auto& [val, indices] : groups) {
int m = indices.size();
vector<long long> prefix(m + 1, 0);
for (int i = 0; i < m; i++) {
prefix[i + 1] = prefix[i] + indices[i];
}
for (int k = 0; k < m; k++) {
long long left = (long long)k * indices[k] - prefix[k];
long long right = (prefix[m] - prefix[k + 1]) - (long long)(m - k - 1) * indices[k];
ans[indices[k]] = left + right;
}
}
return ans;
}
};
