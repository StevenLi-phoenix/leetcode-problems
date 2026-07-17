// @leetcode id=3077 questionId=3313 slug=maximum-strength-of-k-disjoint-subarrays lang=cpp site=leetcode.com title="Maximum Strength of K Disjoint Subarrays"
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 2;

        vector<int> coef(k + 1);
        for (int j = 1; j <= k; j++) {
            int mag = k - j + 1;
            coef[j] = (j % 2 == 1) ? mag : -mag;
        }

        vector<long long> prevDp(n + 1, 0);

        for (int j = 1; j <= k; j++) {
            vector<long long> curIn(n + 1, NEG);
            vector<long long> curDp(n + 1, NEG);

            for (int i = 1; i <= n; i++) {
                long long bestStart = max(curIn[i - 1], prevDp[i - 1]);
                if (bestStart <= NEG / 2) {
                    curIn[i] = NEG;
                } else {
                    curIn[i] = bestStart + (long long)coef[j] * nums[i - 1];
                }
                curDp[i] = max(curDp[i - 1], curIn[i]);
            }

            prevDp = curDp;
        }

        return prevDp[n];
    }
};
