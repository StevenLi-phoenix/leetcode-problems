// @leetcode id=3202 questionId=3491 slug=find-the-maximum-length-of-valid-subsequence-ii lang=cpp site=leetcode.com title="Find the Maximum Length of Valid Subsequence II"
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // For a fixed target remainder m, dp[v] = length of the longest
        // valid chain ending in an element with residue v, where the next
        // element's residue must be (m - v + k) % k to keep the pairwise
        // sum's remainder equal to m.
        int n = nums.size();
        int best = 0;
        for (int m = 0; m < k; m++) {
            vector<int> dp(k, 0);
            for (int i = 0; i < n; i++) {
                int r = nums[i] % k;
                int need = ((m - r) % k + k) % k;
                int newLen = dp[need] + 1;
                dp[r] = max(dp[r], newLen);
                best = max(best, dp[r]);
            }
        }
        return best;
    }
};
