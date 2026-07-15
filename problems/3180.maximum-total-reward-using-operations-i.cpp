// @leetcode id=3180 questionId=3442 slug=maximum-total-reward-using-operations-i lang=cpp site=leetcode.com title="Maximum Total Reward Using Operations I"
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        long long total = 0;
        for (int v : rewardValues) total += v;
        int size = (int)total + 1;
        int words = (size + 63) / 64;

        vector<uint64_t> dp(words, 0);
        dp[0] = 1ULL;

        for (int v : rewardValues) {
            int fullWords = v / 64;
            int rem = v % 64;
            vector<uint64_t> low(words, 0);
            for (int i = 0; i < fullWords && i < words; i++) low[i] = dp[i];
            if (fullWords < words && rem > 0) low[fullWords] = dp[fullWords] & ((1ULL << rem) - 1);

            int wordShift = v / 64;
            int bitShift = v % 64;
            for (int i = words - 1; i >= 0; i--) {
                int srcIdx = i - wordShift;
                uint64_t val = 0;
                if (srcIdx >= 0 && srcIdx < words) {
                    val = low[srcIdx] << bitShift;
                    if (bitShift > 0 && srcIdx - 1 >= 0) val |= low[srcIdx - 1] >> (64 - bitShift);
                }
                dp[i] |= val;
            }
        }

        for (int i = words - 1; i >= 0; i--) {
            if (dp[i]) {
                for (int b = 63; b >= 0; b--) {
                    if ((dp[i] >> b) & 1ULL) return i * 64 + b;
                }
            }
        }
        return 0;
    }
};
