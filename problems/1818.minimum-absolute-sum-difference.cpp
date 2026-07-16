// @leetcode id=1818 questionId=1946 slug=minimum-absolute-sum-difference lang=cpp site=leetcode.com title="Minimum Absolute Sum Difference"
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const long long MOD = 1e9 + 7;
        int n = nums1.size();
        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());

        long long totalDiff = 0;
        long long maxReduction = 0;
        for (int i = 0; i < n; i++) {
            long long diff = abs((long long)nums1[i] - nums2[i]);
            totalDiff += diff;

            auto it = lower_bound(sorted.begin(), sorted.end(), nums2[i]);
            long long best = diff;
            if (it != sorted.end()) best = min(best, (long long)abs((long long)*it - nums2[i]));
            if (it != sorted.begin()) best = min(best, (long long)abs((long long)*prev(it) - nums2[i]));

            maxReduction = max(maxReduction, diff - best);
        }
        return (int)((totalDiff - maxReduction) % MOD);
    }
};
