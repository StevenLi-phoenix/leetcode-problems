// @leetcode id=1337 questionId=1463 slug=the-k-weakest-rows-in-a-matrix lang=cpp site=leetcode.com title="The K Weakest Rows in a Matrix"
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            rows.push_back({count, i});
        }

        sort(rows.begin(), rows.end());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(rows[i].second);
        }

        return result;
    }
};
