// @leetcode id=2643 questionId=2737 slug=row-with-maximum-ones lang=cpp site=leetcode.com title="Row With Maximum Ones"
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int bestRow = 0, bestCount = -1;
        for (int i = 0; i < (int)mat.size(); i++) {
            int count = 0;
            for (int v : mat[i]) count += v;
            if (count > bestCount) {
                bestCount = count;
                bestRow = i;
            }
        }
        return {bestRow, bestCount};
    }
};
