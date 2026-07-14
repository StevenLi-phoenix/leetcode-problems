// @leetcode id=1712 questionId=1831 slug=ways-to-split-array-into-three-subarrays lang=cpp site=leetcode.com title="Ways to Split Array Into Three Subarrays"
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        long long total = 0;
        for (int i = 0; i + 1 < n; i++) {
            long long leftSum = prefix[i + 1];
            // j is the end index (0-indexed) of mid; mid = nums[i+1..j],
            // right = nums[j+1..n-1]. Need j in [i+1, n-2].
            int lo = i + 1, hi = n - 2;
            if (lo > hi) continue;

            // Smallest j with prefix[j+1] >= 2*leftSum (mid >= left).
            int loJ = n; // sentinel meaning "not found"
            {
                int l = lo, r = hi;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (prefix[m + 1] >= 2 * leftSum) { loJ = m; r = m - 1; }
                    else l = m + 1;
                }
            }
            // Largest j with 2*prefix[j+1] <= prefix[n]+leftSum (mid <= right).
            int hiJ = -1;
            {
                int l = lo, r = hi;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (2 * prefix[m + 1] <= prefix[n] + leftSum) { hiJ = m; l = m + 1; }
                    else r = m - 1;
                }
            }

            if (loJ <= hiJ) total = (total + (hiJ - loJ + 1)) % MOD;
        }
        return (int)total;
    }
};
