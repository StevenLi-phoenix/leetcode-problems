// @leetcode id=2809 questionId=2952 slug=minimum-time-to-make-array-sum-at-most-x lang=cpp site=leetcode.com title="Minimum Time to Make Array Sum At Most x"
class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        // Trying T seconds means zeroing exactly T distinct indices at
        // times 1..T (one per second); zeroing index i at time p saves
        // nums1[i] + nums2[i]*p from the final total. For a fixed subset,
        // rearrangement inequality says pairing larger nums2 with larger
        // p maximizes savings, so sorting all indices by nums2 ascending
        // and using position-in-sweep as p (only for selected elements)
        // realizes the optimal assignment for whichever subset is chosen.
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] < nums2[b]; });

        long long sum1 = 0, sum2 = 0;
        for (int v : nums1) sum1 += v;
        for (int v : nums2) sum2 += v;

        const long long NEG = LLONG_MIN / 2;
        vector<long long> dp(n + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int id = idx[i];
            for (int j = min(i + 1, n); j >= 1; j--) {
                if (dp[j - 1] == NEG) continue;
                long long candidate = dp[j - 1] + nums1[id] + (long long)nums2[id] * j;
                dp[j] = max(dp[j], candidate);
            }
        }

        int best = -1;
        for (int T = 0; T <= n; T++) {
            if (dp[T] == NEG) continue;
            long long total = sum1 + (long long)T * sum2 - dp[T];
            if (total <= x) {
                best = T;
                break;
            }
        }
        return best;
    }
};
