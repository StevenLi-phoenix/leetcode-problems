// @leetcode id=3740 questionId=4115 slug=minimum-distance-between-three-equal-elements-i lang=cpp site=leetcode.com title="Minimum Distance Between Three Equal Elements I"
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < (int)nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto& [val, idx] : indices) {
            if ((int)idx.size() < 3) continue;
            for (int m = 0; m + 2 < (int)idx.size(); m++) {
                ans = min(ans, 2 * (idx[m+2] - idx[m]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
