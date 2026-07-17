// @leetcode id=3288 questionId=3571 slug=length-of-the-longest-increasing-path lang=cpp site=leetcode.com title="Length of the Longest Increasing Path"
class Solution {
public:
    struct FenwickMax {
        vector<int> tree;
        int n;
        FenwickMax(int n_) : n(n_), tree(n_ + 1, 0) {}
        void update(int pos, int val) {
            for (; pos <= n; pos += pos & (-pos)) tree[pos] = max(tree[pos], val);
        }
        int query(int pos) {
            int res = 0;
            for (; pos > 0; pos -= pos & (-pos)) res = max(res, tree[pos]);
            return res;
        }
    };

    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();

        vector<int> ys;
        for (auto& c : coordinates) ys.push_back(c[1]);
        vector<int> sortedYs = ys;
        sort(sortedYs.begin(), sortedYs.end());
        sortedYs.erase(unique(sortedYs.begin(), sortedYs.end()), sortedYs.end());
        int m = sortedYs.size();

        auto compress = [&](int y) {
            return lower_bound(sortedYs.begin(), sortedYs.end(), y) - sortedYs.begin() + 1;
        };

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        // dp1: forward, sort by x asc
        sort(order.begin(), order.end(), [&](int a, int b) {
            return coordinates[a][0] < coordinates[b][0];
        });

        vector<int> dp1(n, 1);
        {
            FenwickMax fenwick(m);
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && coordinates[order[j]][0] == coordinates[order[i]][0]) j++;
                // query phase for this x-group
                for (int t = i; t < j; t++) {
                    int idx = order[t];
                    int yc = compress(coordinates[idx][1]);
                    if (yc > 1) dp1[idx] = fenwick.query(yc - 1) + 1;
                }
                // update phase
                for (int t = i; t < j; t++) {
                    int idx = order[t];
                    int yc = compress(coordinates[idx][1]);
                    fenwick.update(yc, dp1[idx]);
                }
                i = j;
            }
        }

        // dp2: backward, sort by x desc
        sort(order.begin(), order.end(), [&](int a, int b) {
            return coordinates[a][0] > coordinates[b][0];
        });

        vector<int> dp2(n, 1);
        {
            // for suffix-max query on y (y > y_i), reindex as (m - compress(y) + 1)
            FenwickMax fenwick(m);
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && coordinates[order[j]][0] == coordinates[order[i]][0]) j++;
                for (int t = i; t < j; t++) {
                    int idx = order[t];
                    int yc = compress(coordinates[idx][1]);
                    int revPos = m - yc + 1; // larger y -> smaller revPos
                    if (revPos > 1) dp2[idx] = fenwick.query(revPos - 1) + 1;
                }
                for (int t = i; t < j; t++) {
                    int idx = order[t];
                    int yc = compress(coordinates[idx][1]);
                    int revPos = m - yc + 1;
                    fenwick.update(revPos, dp2[idx]);
                }
                i = j;
            }
        }

        return dp1[k] + dp2[k] - 1;
    }
};
