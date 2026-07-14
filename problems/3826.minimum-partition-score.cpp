// @leetcode id=3826 questionId=4121 slug=minimum-partition-score lang=cpp site=leetcode.com title="Minimum Partition Score"
class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        const long long INF = LLONG_MAX / 2;
        auto cost = [&](int l, int r) -> long long { // 1-indexed inclusive
            long long s = prefix[r] - prefix[l - 1];
            return s * (s + 1) / 2;
        };

        vector<long long> prev(n + 1, INF), cur(n + 1, INF);
        prev[0] = 0;

        function<void(int, int, int, int)> solve = [&](int lo, int hi, int optLo, int optHi) {
            if (lo > hi) return;
            int mid = (lo + hi) / 2;
            long long best = INF;
            int bestM = optLo;
            int upper = min(mid - 1, optHi);
            for (int m = optLo; m <= upper; m++) {
                if (prev[m] >= INF) continue;
                long long val = prev[m] + cost(m + 1, mid);
                if (val < best) { best = val; bestM = m; }
            }
            cur[mid] = best;
            solve(lo, mid - 1, optLo, bestM);
            solve(mid + 1, hi, bestM, optHi);
        };

        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);
            solve(j, n, j - 1, n - 1);
            prev = cur;
        }

        return prev[n];
    }
};
