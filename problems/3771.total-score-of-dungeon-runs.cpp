// @leetcode id=3771 questionId=4146 slug=total-score-of-dungeon-runs lang=cpp site=leetcode.com title="Total Score of Dungeon Runs"
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + damage[i];

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long threshold = prefix[i + 1] - hp + requirement[i];
            int j0 = lower_bound(prefix.begin(), prefix.begin() + i + 1, threshold) - prefix.begin();
            if (j0 <= i) total += (i - j0 + 1);
        }
        return total;
    }
};
