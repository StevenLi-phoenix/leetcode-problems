// @leetcode id=492 questionId=492 slug=construct-the-rectangle lang=cpp site=leetcode.com title="Construct the Rectangle"
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt((double)area);
        while (w > 0 && area % w != 0) w--;
        return {area / w, w};
    }
};
