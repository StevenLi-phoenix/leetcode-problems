// @leetcode id=3847 questionId=4224 slug=find-the-score-difference-in-a-game lang=cpp site=leetcode.com title="Find the Score Difference in a Game"
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int active = 0;
        int score[2] = {0, 0};
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] % 2 == 1) active ^= 1;
            if (i % 6 == 5) active ^= 1;
            score[active] += nums[i];
        }
        return score[0] - score[1];
    }
};
