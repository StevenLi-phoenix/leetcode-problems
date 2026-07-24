// @leetcode id=2848 questionId=3034 slug=points-that-intersect-with-cars lang=cpp site=leetcode.com title="Points That Intersect With Cars"
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        bool covered[101] = {false};
        for (auto& car : nums) {
            for (int p = car[0]; p <= car[1]; p++) covered[p] = true;
        }
        int count = 0;
        for (int p = 1; p <= 100; p++) {
            if (covered[p]) count++;
        }
        return count;
    }
};
