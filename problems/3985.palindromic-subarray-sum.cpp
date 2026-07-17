// @leetcode id=3985 questionId=4031 slug=palindromic-subarray-sum lang=cpp site=leetcode.com title="Palindromic Subarray Sum"
class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        const long long SENTINEL = LLONG_MIN;

        int m = 2 * n + 1;
        vector<long long> T(m);
        for (int i = 0; i < n; i++) {
            T[2 * i] = SENTINEL;
            T[2 * i + 1] = nums[i];
        }
        T[2 * n] = SENTINEL;

        vector<int> p(m, 0);
        int center = 0, right = 0;
        for (int i = 0; i < m; i++) {
            if (i < right) p[i] = min(right - i, p[2 * center - i]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && T[i - p[i] - 1] == T[i + p[i] + 1]) {
                p[i]++;
            }
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        long long best = 0;
        for (int i = 0; i < m; i++) {
            int l = (i - p[i]) / 2;
            int r = (i + p[i]) / 2 - 1;
            if (l <= r) {
                best = max(best, prefix[r + 1] - prefix[l]);
            }
        }

        return best;
    }
};
