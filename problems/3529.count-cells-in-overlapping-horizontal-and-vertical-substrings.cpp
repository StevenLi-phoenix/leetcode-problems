// @leetcode id=3529 questionId=3821 slug=count-cells-in-overlapping-horizontal-and-vertical-substrings lang=cpp site=leetcode.com title="Count Cells in Overlapping Horizontal and Vertical Substrings"
class Solution {
public:
    vector<int> buildFailure(const string& p) {
        int len = p.size();
        vector<int> fail(len, 0);
        int k = 0;
        for (int i = 1; i < len; i++) {
            while (k > 0 && p[i] != p[k]) k = fail[k - 1];
            if (p[i] == p[k]) k++;
            fail[i] = k;
        }
        return fail;
    }

    vector<int> findMatches(const string& text, const string& pattern, const vector<int>& fail) {
        vector<int> result;
        int k = 0;
        int plen = pattern.size();
        for (int i = 0; i < (int)text.size(); i++) {
            while (k > 0 && text[i] != pattern[k]) k = fail[k - 1];
            if (text[i] == pattern[k]) k++;
            if (k == plen) {
                result.push_back(i - plen + 1);
                k = fail[k - 1];
            }
        }
        return result;
    }

    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        int plen = pattern.size();

        string rowMajor(total, ' ');
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowMajor[i * n + j] = grid[i][j];
            }
        }

        string colMajor(total, ' ');
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colMajor[j * m + i] = grid[i][j];
            }
        }

        vector<int> fail = buildFailure(pattern);
        vector<int> rowMatches = findMatches(rowMajor, pattern, fail);
        vector<int> colMatches = findMatches(colMajor, pattern, fail);

        vector<int> diffH(total + 1, 0);
        for (int start : rowMatches) {
            diffH[start]++;
            diffH[start + plen]--;
        }
        vector<int> diffV(total + 1, 0);
        for (int start : colMatches) {
            diffV[start]++;
            diffV[start + plen]--;
        }

        vector<bool> coveredH(total, false), coveredV(total, false);
        int running = 0;
        for (int i = 0; i < total; i++) {
            running += diffH[i];
            coveredH[i] = running > 0;
        }
        running = 0;
        for (int i = 0; i < total; i++) {
            running += diffV[i];
            coveredV[i] = running > 0;
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int rowIdx = i * n + j;
                int colIdx = j * m + i;
                if (coveredH[rowIdx] && coveredV[colIdx]) count++;
            }
        }
        return count;
    }
};
