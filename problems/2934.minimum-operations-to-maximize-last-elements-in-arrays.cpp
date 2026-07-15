// @leetcode id=2934 questionId=3190 slug=minimum-operations-to-maximize-last-elements-in-arrays lang=cpp site=leetcode.com title="Minimum Operations to Maximize Last Elements in Arrays"
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        auto tryScenario = [&](bool swapLast) -> int {
            int target1 = swapLast ? nums2[n - 1] : nums1[n - 1];
            int target2 = swapLast ? nums1[n - 1] : nums2[n - 1];
            int cost = swapLast ? 1 : 0;
            for (int i = 0; i < n - 1; i++) {
                bool noSwapOk = nums1[i] <= target1 && nums2[i] <= target2;
                bool swapOk = nums2[i] <= target1 && nums1[i] <= target2;
                if (noSwapOk && swapOk) continue;
                else if (noSwapOk) continue;
                else if (swapOk) cost++;
                else return INT_MAX;
            }
            return cost;
        };

        int a = tryScenario(false);
        int b = tryScenario(true);
        int best = min(a, b);
        return best == INT_MAX ? -1 : best;
    }
};
