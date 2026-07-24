// @leetcode id=3898 questionId=4271 slug=find-the-degree-of-each-vertex lang=cpp site=leetcode.com title="Find the Degree of Each Vertex"
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i] += matrix[i][j];
            }
        }
        return ans;
    }
};
