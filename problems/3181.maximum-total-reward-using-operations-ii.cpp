// @leetcode id=3181 questionId=3443 slug=maximum-total-reward-using-operations-ii lang=cpp site=leetcode.com title="Maximum Total Reward Using Operations II"
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        const int MAXV = 100001;
        bitset<MAXV> dp;
        dp[0] = 1;

        for (int v : rewardValues) {
            bitset<MAXV> lowMask = (bitset<MAXV>().set() >> (MAXV - v)); // bits 0..v-1 set
            if (v == 0) continue;
            bitset<MAXV> masked = dp & lowMask;
            dp |= (masked << v);
        }

        for (int i = MAXV - 1; i >= 0; i--) {
            if (dp[i]) return i;
        }

        return 0;
    }
};
