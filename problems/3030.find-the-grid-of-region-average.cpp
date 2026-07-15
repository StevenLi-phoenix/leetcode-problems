// @leetcode id=3030 questionId=3272 slug=find-the-grid-of-region-average lang=cpp site=leetcode.com title="Find the Grid of Region Average"
class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size();
        vector<vector<long long>> sum(m, vector<long long>(n, 0));
        vector<vector<int>> cnt(m, vector<int>(n, 0));

        for (int r = 0; r + 2 < m; r++) {
            for (int c = 0; c + 2 < n; c++) {
                bool valid = true;
                for (int i = r; i <= r + 2 && valid; i++) {
                    for (int j = c; j <= c + 2 && valid; j++) {
                        if (i + 1 <= r + 2 && abs(image[i][j] - image[i + 1][j]) > threshold) valid = false;
                        if (j + 1 <= c + 2 && abs(image[i][j] - image[i][j + 1]) > threshold) valid = false;
                    }
                }
                if (!valid) continue;

                long long total = 0;
                for (int i = r; i <= r + 2; i++)
                    for (int j = c; j <= c + 2; j++)
                        total += image[i][j];
                int avg = (int)(total / 9);

                for (int i = r; i <= r + 2; i++) {
                    for (int j = c; j <= c + 2; j++) {
                        sum[i][j] += avg;
                        cnt[i][j]++;
                    }
                }
            }
        }

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = cnt[i][j] ? (int)(sum[i][j] / cnt[i][j]) : image[i][j];
            }
        }
        return result;
    }
};
