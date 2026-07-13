// @leetcode id=3177 questionId=3452 slug=find-the-maximum-length-of-a-good-subsequence-ii lang=cpp site=leetcode.com title="Find the Maximum Length of a Good Subsequence II"
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // dp[i][j] = best subsequence length ending at i using j mismatch
        // budget. Rather than scanning all previous i' (O(n^2 k)), track
        // per-value best-so-far (free extension, same value) and an
        // overall best-so-far (costs one mismatch, any value).
        int n = nums.size();
        unordered_map<int, vector<int>> valueBest;
        vector<int> overallBest(k + 1, 0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            auto it = valueBest.find(v);
            if (it == valueBest.end()) {
                it = valueBest.emplace(v, vector<int>(k + 1, 0)).first;
            }
            vector<int>& same = it->second;

            vector<int> cur(k + 1);
            for (int j = 0; j <= k; j++) {
                int fromSame = same[j] + 1;
                int fromDiff = (j > 0) ? overallBest[j - 1] + 1 : 0;
                cur[j] = max({fromSame, fromDiff, 1});
                ans = max(ans, cur[j]);
            }

            for (int j = 0; j <= k; j++) {
                same[j] = max(same[j], cur[j]);
                overallBest[j] = max(overallBest[j], cur[j]);
            }
        }
        return ans;
    }
};
