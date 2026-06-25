// @leetcode id=1886 questionId=2015 slug=determine-whether-matrix-can-be-obtained-by-rotation lang=cpp site=leetcode.com title="Determine Whether Matrix Can Be Obtained By Rotation"
class Solution {
    public:
    void rotate(vector<vector<int>>& m) {
    int n = m.size();
    for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
    swap(m[i][j], m[j][i]);
    for (int i = 0; i < n; i++)
    reverse(m[i].begin(), m[i].end());
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int i = 0; i < 4; i++) {
    if (mat == target) return true;
    rotate(mat);
    }
    return false;
    }
    };
