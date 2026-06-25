// @leetcode id=1458 questionId=1569 slug=max-dot-product-of-two-subsequences lang=cpp site=leetcode.com title="Max Dot Product of Two Subsequences"
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size(), m = (int)nums2.size();
        const long long NEG = -(1LL << 60);

        vector<long long> prev(m + 1, NEG), cur(m + 1, NEG);

        for (int i = 1; i <= n; i++) {
            cur[0] = NEG;
            for (int j = 1; j <= m; j++) {
                long long prod = 1LL * nums1[i - 1] * nums2[j - 1];

                // take (i-1, j-1) as a pair, either start new or extend dp[i-1][j-1]
                long long best_pair = prod;
                if (prev[j - 1] != NEG) best_pair = max(best_pair, prev[j - 1] + prod);

                // skip from nums1 or nums2, or use the pair
                cur[j] = max({prev[j], cur[j - 1], best_pair});
            }
            swap(prev, cur);
        }

        return (int)prev[m];
    }
};
