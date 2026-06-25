// @leetcode id=3516 questionId=3830 slug=find-closest-person lang=cpp site=leetcode.com title="Find Closest Person"
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);

        if (dist1 < dist2) return 1;
        if (dist2 < dist1) return 2;
        return 0;
    }
};
