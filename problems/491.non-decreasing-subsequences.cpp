// @leetcode id=491 questionId=491 slug=non-decreasing-subsequences lang=cpp site=leetcode.com title="Non-decreasing Subsequences"
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> current;
        dfs(nums, 0, current, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
    
    void dfs(vector<int>& nums, int start, vector<int>& current, set<vector<int>>& result) {
        if (current.size() >= 2) {
            result.insert(current);
        }
        unordered_set<int> used;
        for (int i = start; i < (int)nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (current.empty() || nums[i] >= current.back()) {
                used.insert(nums[i]);
                current.push_back(nums[i]);
                dfs(nums, i + 1, current, result);
                current.pop_back();
            }
        }
    }
};
