// @leetcode id=1638 questionId=1743 slug=count-substrings-that-differ-by-one-character lang=cpp site=leetcode.com title="Count Substrings That Differ by One Character"
class Solution {
public:
    int countSubstrings(string s, string t) {
        // Fix (i, j) as the position of the single mismatch; the number of
        // valid substring pairs anchored there is (matching-run-left + 1) *
        // (matching-run-right + 1), since either side can independently
        // extend as far as characters keep matching.
        int n = s.size(), m = t.size();
        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) left[i][j] = left[i - 1][j - 1] + 1;

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                if (i < n - 1 && j < m - 1 && s[i + 1] == t[j + 1]) right[i][j] = right[i + 1][j + 1] + 1;

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i] != t[j]) count += (left[i][j] + 1) * (right[i][j] + 1);

        return count;
    }
};
