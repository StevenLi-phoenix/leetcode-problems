// @leetcode id=3741 questionId=4119 slug=minimum-distance-between-three-equal-elements-ii lang=cpp site=leetcode.com title="Minimum Distance Between Three Equal Elements II"
class Solution {
    public:
    int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < (int)nums.size(); i++) {
    pos[nums[i]].push_back(i);
    }
    int ans = INT_MAX;
    for (auto& [val, indices] : pos) {
    int n = indices.size();
    if (n < 3) continue;
    for (int t = 0; t + 2 < n; t++) {
    ans = min(ans, 2 * (indices[t + 2] - indices[t]));
    }
    }
    return ans == INT_MAX ? -1 : ans;
    }
    };
