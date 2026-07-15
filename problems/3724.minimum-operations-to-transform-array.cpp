// @leetcode id=3724 questionId=4042 slug=minimum-operations-to-transform-array lang=cpp site=leetcode.com title="Minimum Operations to Transform Array"
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long baseCost = 0;
        for (int i = 0; i < n; i++) baseCost += abs(nums2[i] - nums1[i]);

        int appendTarget = nums2[n];
        long long bestTerm = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int a = nums1[i], b = nums2[i], c = appendTarget;
            int mx = max({a, b, c}), mn = min({a, b, c});
            long long spread = mx - mn;
            long long diff = abs(b - a);
            bestTerm = min(bestTerm, spread - diff);
        }

        return baseCost + 1 + bestTerm;
    }
};
