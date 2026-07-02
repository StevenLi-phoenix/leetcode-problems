// @leetcode id=1738 questionId=1860 slug=find-kth-largest-xor-coordinate-value lang=cpp site=leetcode.com title="Find Kth Largest XOR Coordinate Value"
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        vector<int> values;
        values.reserve(m * n);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i-1][j] ^ prefix[i][j-1] ^ prefix[i-1][j-1] ^ matrix[i-1][j-1];
                values.push_back(prefix[i][j]);
            }
        }
        nth_element(values.begin(), values.begin() + k - 1, values.end(), greater<int>());
        return values[k - 1];
    }
};
