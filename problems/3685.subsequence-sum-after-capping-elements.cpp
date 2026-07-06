// @leetcode id=3685 questionId=3873 slug=subsequence-sum-after-capping-elements lang=cpp site=leetcode.com title="Subsequence Sum After Capping Elements"
class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (int v : nums) ++count[v];

        vector<bool> reachable(k + 1, false);
        reachable[0] = true;

        vector<bool> ans(n, false);
        int processed = 0;

        for (int x = 1; x <= n; ++x) {
            for (int c = 0; c < count[x]; ++c) {
                for (int j = k; j >= x; --j) {
                    if (reachable[j - x]) reachable[j] = true;
                }
            }
            processed += count[x];
            int remaining = n - processed;

            bool found = false;
            for (long long t = 0; t <= remaining; ++t) {
                long long rem = (long long)k - t * x;
                if (rem < 0) break;
                if (reachable[rem]) { found = true; break; }
            }
            ans[x - 1] = found;
        }
        return ans;
    }
};
