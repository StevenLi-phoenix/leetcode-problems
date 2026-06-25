// @leetcode id=1074 questionId=1145 slug=number-of-submatrices-that-sum-to-target lang=cpp site=leetcode.com title="Number of Submatrices That Sum to Target"
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        
        // Compute 2D prefix sums
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = matrix[i-1][j-1] 
                              + prefix[i-1][j] 
                              + prefix[i][j-1] 
                              - prefix[i-1][j-1];
            }
        }
        
        // Fix top row r1 and bottom row r2, then use hashmap for columns
        for (int r1 = 1; r1 <= m; r1++) {
            for (int r2 = r1; r2 <= m; r2++) {
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                for (int c = 1; c <= n; c++) {
                    // Sum of submatrix from row r1 to r2, column 1 to c
                    int sum = prefix[r2][c] - prefix[r1-1][c];
                    // We want sum - prev_sum = target => prev_sum = sum - target
                    if (cnt.count(sum - target)) {
                        result += cnt[sum - target];
                    }
                    cnt[sum]++;
                }
            }
        }
        
        return result;
    }
};
