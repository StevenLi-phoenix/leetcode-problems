// @leetcode id=3996 questionId=4369 slug=even-number-of-knight-moves lang=cpp site=leetcode.com title="Even Number of Knight Moves"
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int sumStart = start[0] + start[1];
        int sumTarget = target[0] + target[1];
        return (sumStart % 2) == (sumTarget % 2);
    }
};
