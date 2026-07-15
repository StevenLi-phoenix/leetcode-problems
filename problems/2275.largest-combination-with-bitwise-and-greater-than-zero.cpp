// @leetcode id=2275 questionId=2356 slug=largest-combination-with-bitwise-and-greater-than-zero lang=cpp site=leetcode.com title="Largest Combination With Bitwise AND Greater Than Zero"
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int best = 0;
        for (int bit = 0; bit < 24; bit++) {
            int count = 0;
            for (int x : candidates) {
                if (x & (1 << bit)) count++;
            }
            best = max(best, count);
        }
        return best;
    }
};
