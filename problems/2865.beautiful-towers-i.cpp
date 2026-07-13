// @leetcode id=2865 questionId=3114 slug=beautiful-towers-i lang=cpp site=leetcode.com title="Beautiful Towers I"
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long best = 0;
        for (int peak = 0; peak < n; peak++) {
            long long sum = heights[peak];
            long long cap = heights[peak];
            for (int i = peak - 1; i >= 0; i--) {
                cap = min(cap, (long long)heights[i]);
                sum += cap;
            }
            cap = heights[peak];
            for (int i = peak + 1; i < n; i++) {
                cap = min(cap, (long long)heights[i]);
                sum += cap;
            }
            best = max(best, sum);
        }
        return best;
    }
};
