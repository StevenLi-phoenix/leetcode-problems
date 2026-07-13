// @leetcode id=2679 questionId=2728 slug=sum-in-a-matrix lang=cpp site=leetcode.com title="Sum in a Matrix"
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) sort(row.begin(), row.end(), greater<int>());

        int cols = nums[0].size();
        int score = 0;
        for (int c = 0; c < cols; c++) {
            int best = 0;
            for (auto& row : nums) best = max(best, row[c]);
            score += best;
        }
        return score;
    }
};
