// @leetcode id=3200 questionId=3469 slug=maximum-height-of-a-triangle lang=cpp site=leetcode.com title="Maximum Height of a Triangle"
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(simulate(red, blue), simulate(blue, red));
    }

private:
    int simulate(int first, int second) {
        int height = 0;
        for (int row = 1; ; row++) {
            int& available = (row % 2 == 1) ? first : second;
            if (available < row) break;
            available -= row;
            height++;
        }
        return height;
    }
};
