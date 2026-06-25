// @leetcode id=2718 questionId=2838 slug=sum-of-matrix-after-queries lang=cpp site=leetcode.com title="Sum of Matrix After Queries"
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        unordered_set<int> seenRows, seenCols;
        int q = queries.size();
        
        // Process in reverse order
        for (int i = q - 1; i >= 0; i--) {
            int type = queries[i][0];
            int idx = queries[i][1];
            int val = queries[i][2];
            
            if (type == 0) { // row query
                if (seenRows.find(idx) == seenRows.end()) {
                    seenRows.insert(idx);
                    // cells not covered by column queries
                    ans += (long long)(n - (int)seenCols.size()) * val;
                }
            } else { // col query
                if (seenCols.find(idx) == seenCols.end()) {
                    seenCols.insert(idx);
                    // cells not covered by row queries
                    ans += (long long)(n - (int)seenRows.size()) * val;
                }
            }
        }
        
        return ans;
    }
};
