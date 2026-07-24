// @leetcode id=1725 questionId=1843 slug=number-of-rectangles-that-can-form-the-largest-square lang=cpp site=leetcode.com title="Number Of Rectangles That Can Form The Largest Square"
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxSide = 0, count = 0;
        for (auto& r : rectangles) {
            int side = min(r[0], r[1]);
            if (side > maxSide) {
                maxSide = side;
                count = 1;
            } else if (side == maxSide) {
                count++;
            }
        }
        return count;
    }
};
