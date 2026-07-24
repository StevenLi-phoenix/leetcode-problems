// @leetcode id=3736 questionId=4116 slug=minimum-moves-to-equal-array-elements-iii lang=cpp site=leetcode.com title="Minimum Moves to Equal Array Elements III"
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for (int x : nums) moves += maxVal - x;
        return moves;
    }
};
