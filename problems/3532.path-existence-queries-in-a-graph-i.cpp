// @leetcode id=3532 questionId=3838 slug=path-existence-queries-in-a-graph-i lang=cpp site=leetcode.com title="Path Existence Queries in a Graph I"
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Assign component IDs: increment when consecutive diff > maxDiff
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i-1] + (nums[i] - nums[i-1] > maxDiff ? 1 : 0);
        }
        
        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(comp[u] == comp[v]);
        }
        return ans;
    }
};
