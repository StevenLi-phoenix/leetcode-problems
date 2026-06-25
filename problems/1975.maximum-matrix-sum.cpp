// @leetcode id=1975 questionId=2089 slug=maximum-matrix-sum lang=cpp site=leetcode.com title="Maximum Matrix Sum"
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sumAbs = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto& row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                int ax = std::abs(x);
                sumAbs += (long long)ax;
                minAbs = std::min(minAbs, ax);
            }
        }

        // If odd negatives and no zero (minAbs > 0), one cell must remain negative.
        if (negCount % 2 == 1 && minAbs > 0) {
            sumAbs -= 2LL * minAbs;
        }
        return sumAbs;
    }
};
