// @leetcode id=2965 questionId=3227 slug=find-missing-and-repeated-values lang=cpp site=leetcode.com title="Find Missing and Repeated Values"
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }

        int repeated = 0, missing = 0;
        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 2) {
                repeated = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
        }

        return {repeated, missing};
    }
};
