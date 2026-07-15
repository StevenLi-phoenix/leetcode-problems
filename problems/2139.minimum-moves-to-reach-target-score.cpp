// @leetcode id=2139 questionId=1303 slug=minimum-moves-to-reach-target-score lang=cpp site=leetcode.com title="Minimum Moves to Reach Target Score"
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long t = target;
        int moves = 0;
        while (t > 1 && maxDoubles > 0) {
            if (t % 2 == 1) {
                t--;
                moves++;
            } else {
                t /= 2;
                moves++;
                maxDoubles--;
            }
        }
        moves += (t - 1);
        return moves;
    }
};
