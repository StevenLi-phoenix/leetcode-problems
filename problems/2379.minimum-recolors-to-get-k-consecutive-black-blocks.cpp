// @leetcode id=2379 questionId=2463 slug=minimum-recolors-to-get-k-consecutive-black-blocks lang=cpp site=leetcode.com title="Minimum Recolors to Get K Consecutive Black Blocks"
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }

        int best = whiteCount;
        for (int i = k; i < (int)blocks.size(); i++) {
            if (blocks[i] == 'W') whiteCount++;
            if (blocks[i - k] == 'W') whiteCount--;
            best = min(best, whiteCount);
        }
        return best;
    }
};
