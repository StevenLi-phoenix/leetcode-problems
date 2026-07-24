// @leetcode id=2582 questionId=2645 slug=pass-the-pillow lang=cpp site=leetcode.com title="Pass the Pillow"
class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2 * (n - 1);
        int r = time % cycle;
        return r < n ? r + 1 : 2 * n - 1 - r;
    }
};
