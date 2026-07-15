// @leetcode id=2155 questionId=2261 slug=all-divisions-with-the-highest-score-of-a-binary-array lang=cpp site=leetcode.com title="All Divisions With the Highest Score of a Binary Array"
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int onesRight = 0;
        for (int x : nums) onesRight += x;

        int zerosLeft = 0;
        int bestScore = onesRight;
        vector<int> result = {0};

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zerosLeft++;
            else onesRight--;

            int score = zerosLeft + onesRight;
            if (score > bestScore) {
                bestScore = score;
                result = {i + 1};
            } else if (score == bestScore) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
