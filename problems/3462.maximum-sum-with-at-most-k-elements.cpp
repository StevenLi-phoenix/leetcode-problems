// @leetcode id=3462 questionId=3764 slug=maximum-sum-with-at-most-k-elements lang=cpp site=leetcode.com title="Maximum Sum With at Most K Elements"
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> candidates;
        for (size_t i = 0; i < grid.size(); i++) {
            vector<int> row = grid[i];
            sort(row.begin(), row.end(), greater<int>());
            int take = min((int)row.size(), limits[i]);
            for (int j = 0; j < take; j++) candidates.push_back(row[j]);
        }

        sort(candidates.begin(), candidates.end(), greater<int>());

        long long sum = 0;
        int count = min((int)candidates.size(), k);
        for (int i = 0; i < count; i++) sum += candidates[i];
        return sum;
    }
};
