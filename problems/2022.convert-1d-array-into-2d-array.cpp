// @leetcode id=2022 questionId=2132 slug=convert-1d-array-into-2d-array lang=cpp site=leetcode.com title="Convert 1D Array Into 2D Array"
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if ((int)original.size() != m * n) return {};

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < (int)original.size(); i++) {
            result[i / n][i % n] = original[i];
        }
        return result;
    }
};
