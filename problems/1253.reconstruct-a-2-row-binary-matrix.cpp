// @leetcode id=1253 questionId=1379 slug=reconstruct-a-2-row-binary-matrix lang=cpp site=leetcode.com title="Reconstruct a 2-Row Binary Matrix"
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> result(2, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                if (upper <= 0 || lower <= 0) return {};
                result[0][i] = 1;
                result[1][i] = 1;
                upper--;
                lower--;
            } else if (colsum[i] == 1) {
                if (upper >= lower) {
                    result[0][i] = 1;
                    upper--;
                } else {
                    result[1][i] = 1;
                    lower--;
                }
            }
        }

        if (upper != 0 || lower != 0) return {};
        return result;
    }
};
