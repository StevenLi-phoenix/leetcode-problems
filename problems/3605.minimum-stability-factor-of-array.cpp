// @leetcode id=3605 questionId=3920 slug=minimum-stability-factor-of-array lang=cpp site=leetcode.com title="Minimum Stability Factor of Array"
class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> sparse(LOG, vector<int>(n));
        sparse[0] = nums;
        for (int k = 1; k < LOG; k++) {
            int len = 1 << k, half = 1 << (k - 1);
            for (int i = 0; i + len <= n; i++) {
                sparse[k][i] = gcd(sparse[k - 1][i], sparse[k - 1][i + half]);
            }
        }

        auto queryGcd = [&](int l, int r) -> int { // inclusive
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);
            return gcd(sparse[k][l], sparse[k][r - (1 << k) + 1]);
        };

        auto feasible = [&](int L) -> bool {
            // window length L+1; check min hitting set <= maxC
            int windowLen = L + 1;
            if (windowLen > n) return true;
            int count = 0;
            int lastPoint = -1;
            for (int i = 0; i + windowLen - 1 < n; i++) {
                int r = i + windowLen - 1;
                if (lastPoint >= i) continue; // already covered
                int g = queryGcd(i, r);
                if (g >= 2) {
                    count++;
                    lastPoint = r;
                    if (count > maxC) return false;
                }
            }
            return count <= maxC;
        };

        int lo = 0, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
