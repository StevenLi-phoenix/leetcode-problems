// @leetcode id=944 questionId=981 slug=delete-columns-to-make-sorted lang=cpp site=leetcode.com title="Delete Columns to Make Sorted"
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = (int)strs.size();
        int m = (int)strs[0].size();
        int del = 0;

        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    del++;
                    break; // this column is bad, move to next column
                }
            }
        }
        return del;
    }
};
