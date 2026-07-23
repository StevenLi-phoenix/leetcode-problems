// @leetcode id=2498 questionId=2591 slug=frog-jump-ii lang=cpp site=leetcode.com title="Frog Jump II"
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if (n == 2) return stones[1] - stones[0];

        int best = max(stones[1] - stones[0], stones[n - 1] - stones[n - 2]);
        for (int i = 0; i + 2 < n; i++) {
            best = max(best, stones[i + 2] - stones[i]);
        }
        return best;
    }
};
