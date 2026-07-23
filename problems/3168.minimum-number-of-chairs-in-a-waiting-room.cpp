// @leetcode id=3168 questionId=3426 slug=minimum-number-of-chairs-in-a-waiting-room lang=cpp site=leetcode.com title="Minimum Number of Chairs in a Waiting Room"
class Solution {
public:
    int minimumChairs(string s) {
        int current = 0, best = 0;
        for (char c : s) {
            if (c == 'E') current++;
            else current--;
            best = max(best, current);
        }
        return best;
    }
};
