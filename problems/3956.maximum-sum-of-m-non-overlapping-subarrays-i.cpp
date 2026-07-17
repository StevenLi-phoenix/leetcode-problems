// @leetcode id=3956 questionId=4123 slug=maximum-sum-of-m-non-overlapping-subarrays-i lang=cpp site=leetcode.com title="Maximum Sum of M Non-Overlapping Subarrays I"
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 2;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> dpPrev(n + 1, 0);

        for (int k = 1; k <= m; k++) {
            vector<long long> dpCur(n + 1, NEG);
            deque<int> dq;

            for (int i = 1; i <= n; i++) {
                int newJ = i - l;
                if (newJ >= 0 && dpPrev[newJ] > NEG / 2) {
                    long long gval = dpPrev[newJ] - prefix[newJ];
                    while (!dq.empty() && (dpPrev[dq.back()] - prefix[dq.back()]) <= gval) dq.pop_back();
                    dq.push_back(newJ);
                }
                while (!dq.empty() && dq.front() < i - r) dq.pop_front();

                long long best = dpCur[i - 1];
                if (k >= 2) best = max(best, dpPrev[i]);
                if (!dq.empty()) {
                    long long gval = dpPrev[dq.front()] - prefix[dq.front()];
                    best = max(best, prefix[i] + gval);
                }
                dpCur[i] = best;
            }

            dpPrev = dpCur;
        }

        return dpPrev[n];
    }
};
