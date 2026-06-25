// @leetcode id=2946 questionId=3215 slug=matrix-similarity-after-cyclic-shifts lang=cpp site=leetcode.com title="Matrix Similarity After Cyclic Shifts"
class Solution {
    public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    k %= n;
    if (k == 0) return true;
    for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
    int src;
    if (i % 2 == 0) src = (j + k) % n;
    else src = (j - k % n + n) % n;
    if (mat[i][j] != mat[i][src]) return false;
    }
    }
    return true;
    }
    };
