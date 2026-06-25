// @leetcode id=1884 questionId=2031 slug=egg-drop-with-2-eggs-and-n-floors lang=cpp site=leetcode.com title="Egg Drop With 2 Eggs and N Floors"
class Solution {
public:
    int twoEggDrop(int n) {
        // With 2 eggs, minimum moves t satisfies: t*(t+1)/2 >= n
        // Find smallest t such that t*(t+1)/2 >= n
        int t = 1;
        while (t * (t + 1) / 2 < n) {
            t++;
        }
        return t;
    }
};
