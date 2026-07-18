// @leetcode id=3920 questionId=4294 slug=maximize-fixed-points-after-deletions lang=cpp site=leetcode.com title="Maximize Fixed Points After Deletions"
class Solution {
public:
    vector<int> fenw; // max-fenwick over value (1-indexed)
    int maxVal;

    vector<int> value_, delta_, dp_;
    vector<int> sortBuf, touchedBuf;

    void fenwUpdate(int pos, int val) {
        for (int i = pos; i <= maxVal; i += i & (-i)) {
            if (fenw[i] < val) fenw[i] = val;
            touchedBuf.push_back(i);
        }
    }

    int fenwQuery(int pos) {
        int res = -1;
        for (int i = pos; i > 0; i -= i & (-i)) {
            res = max(res, fenw[i]);
        }
        return res;
    }

    void solve(int l, int r) {
        if (r - l <= 1) return;
        int mid = (l + r) / 2;
        solve(l, mid);

        // Cross contribution: left half -> right half. Sort [l,r) by delta into sortBuf,
        // processing left-half insertions before right-half queries on ties.
        for (int p = l; p < r; p++) sortBuf[p] = p;
        sort(sortBuf.begin() + l, sortBuf.begin() + r, [&](int a, int b) {
            if (delta_[a] != delta_[b]) return delta_[a] < delta_[b];
            return (a < mid) && !(b < mid); // ties: left-half entries first
        });

        touchedBuf.clear();
        for (int p = l; p < r; p++) {
            int idx = sortBuf[p];
            if (idx < mid) {
                fenwUpdate(value_[idx] + 1, dp_[idx]);
            } else if (value_[idx] > 0) {
                int best = fenwQuery(value_[idx]);
                if (best != -1) dp_[idx] = max(dp_[idx], best + 1);
            }
        }
        for (int t : touchedBuf) fenw[t] = -1;

        solve(mid, r);
    }

    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<int> candIdx;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i) candIdx.push_back(i);
        }

        int m = candIdx.size();
        if (m == 0) return 0;

        value_.resize(m);
        delta_.resize(m);
        dp_.assign(m, 1);

        maxVal = 0;
        for (int k = 0; k < m; k++) {
            int i = candIdx[k];
            value_[k] = nums[i];
            delta_[k] = i - nums[i];
            maxVal = max(maxVal, value_[k] + 1);
        }

        fenw.assign(maxVal + 2, -1);
        sortBuf.resize(m);

        solve(0, m);

        int ans = 0;
        for (int k = 0; k < m; k++) ans = max(ans, dp_[k]);

        return ans;
    }
};
