// @leetcode id=1051 questionId=1137 slug=height-checker lang=cpp site=leetcode.com title="Height Checker"
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        int count = 0;
        for (int i = 0; i < (int)heights.size(); i++) {
            if (heights[i] != expected[i]) count++;
        }
        return count;
    }
};
