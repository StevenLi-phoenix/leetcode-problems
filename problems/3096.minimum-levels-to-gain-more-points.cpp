// @leetcode id=3096 questionId=3355 slug=minimum-levels-to-gain-more-points lang=cpp site=leetcode.com title="Minimum Levels to Gain More Points"
class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        long long total = 0;
        for (int p : possible) total += (p == 1) ? 1 : -1;

        long long alice = 0;
        for (int i = 0; i < n - 1; i++) {
            alice += (possible[i] == 1) ? 1 : -1;
            long long bob = total - alice;
            if (alice > bob) return i + 1;
        }
        return -1;
    }
};
