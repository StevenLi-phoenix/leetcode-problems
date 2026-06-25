// @leetcode id=955 questionId=992 slug=delete-columns-to-make-sorted-ii lang=cpp site=leetcode.com title="Delete Columns to Make Sorted II"
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = (int)strs.size();
        int m = (int)strs[0].size();
        vector<bool> fixed(n - 1, false); // fixed[i] means strs[i] < strs[i+1] is already decided
        int deletions = 0;

        for (int col = 0; col < m; col++) {
            // Check if keeping this column would violate lex order for any unresolved pair
            bool bad = false;
            for (int i = 0; i < n - 1; i++) {
                if (!fixed[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                deletions++;
                continue; // delete this column
            }

            // Keep this column: update which pairs become fixed
            for (int i = 0; i < n - 1; i++) {
                if (!fixed[i] && strs[i][col] < strs[i + 1][col]) {
                    fixed[i] = true;
                }
            }
        }

        return deletions;
    }
};
