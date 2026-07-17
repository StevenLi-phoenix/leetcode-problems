// @leetcode id=1655 questionId=1758 slug=distribute-repeating-integers lang=cpp site=leetcode.com title="Distribute Repeating Integers"
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        vector<int> counts;
        for (auto& [k, v] : freq) counts.push_back(v);

        int m = quantity.size();
        int full = 1 << m;

        vector<int> sumMask(full, 0);
        for (int mask = 1; mask < full; mask++) {
            int lsb = mask & (-mask);
            int idx = __builtin_ctz(lsb);
            sumMask[mask] = sumMask[mask ^ lsb] + quantity[idx];
        }

        vector<bool> dp(full, false);
        dp[0] = true;

        for (int c : counts) {
            vector<bool> newDp = dp;
            for (int mask = 1; mask < full; mask++) {
                if (newDp[mask]) continue;
                for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                    if (sumMask[sub] <= c && dp[mask ^ sub]) {
                        newDp[mask] = true;
                        break;
                    }
                }
            }
            dp = newDp;
            if (dp[full - 1]) return true;
        }

        return dp[full - 1];
    }
};
