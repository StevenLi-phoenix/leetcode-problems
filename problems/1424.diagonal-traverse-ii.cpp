// @leetcode id=1424 questionId=1539 slug=diagonal-traverse-ii lang=cpp site=leetcode.com title="Diagonal Traverse II"
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> diag; // diag[d] holds values for i+j==d, in order of decreasing i
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < (int)nums[i].size(); j++) {
                int d = i + j;
                if (d >= (int)diag.size()) diag.resize(d + 1);
                diag[d].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for (auto& group : diag) {
            for (int v : group) ans.push_back(v);
        }
        return ans;
    }
};
