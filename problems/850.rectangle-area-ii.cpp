// @leetcode id=850 questionId=880 slug=rectangle-area-ii lang=cpp site=leetcode.com title="Rectangle Area II"
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const long long MOD = 1000000007;
        vector<long long> xs, ys;
        for (auto& r : rectangles) {
            xs.push_back(r[0]);
            xs.push_back(r[2]);
            ys.push_back(r[1]);
            ys.push_back(r[3]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int nx = xs.size(), ny = ys.size();
        vector<vector<bool>> covered(nx - 1 > 0 ? nx - 1 : 0, vector<bool>(ny - 1 > 0 ? ny - 1 : 0, false));

        for (auto& r : rectangles) {
            int xi1 = lower_bound(xs.begin(), xs.end(), (long long)r[0]) - xs.begin();
            int xi2 = lower_bound(xs.begin(), xs.end(), (long long)r[2]) - xs.begin();
            int yi1 = lower_bound(ys.begin(), ys.end(), (long long)r[1]) - ys.begin();
            int yi2 = lower_bound(ys.begin(), ys.end(), (long long)r[3]) - ys.begin();

            for (int i = xi1; i < xi2; i++) {
                for (int j = yi1; j < yi2; j++) {
                    covered[i][j] = true;
                }
            }
        }

        long long total = 0;
        for (int i = 0; i + 1 < nx; i++) {
            long long width = xs[i + 1] - xs[i];
            for (int j = 0; j + 1 < ny; j++) {
                if (covered[i][j]) {
                    long long height = ys[j + 1] - ys[j];
                    total = (total + (width % MOD) * (height % MOD)) % MOD;
                }
            }
        }

        return (int)total;
    }
};
