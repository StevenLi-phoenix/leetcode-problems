// @leetcode id=1131 questionId=1230 slug=maximum-of-absolute-value-expression lang=cpp site=leetcode.com title="Maximum of Absolute Value Expression"
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int signs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int best = 0;

        for (auto& s : signs) {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for (int i = 0; i < n; i++) {
                int val = s[0] * arr1[i] + s[1] * arr2[i] + i;
                minVal = min(minVal, val);
                maxVal = max(maxVal, val);
            }
            best = max(best, maxVal - minVal);
        }
        return best;
    }
};
