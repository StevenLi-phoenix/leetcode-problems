// @leetcode id=2928 questionId=3199 slug=distribute-candies-among-children-i lang=cpp site=leetcode.com title="Distribute Candies Among Children I"
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for (int a = 0; a <= limit; a++) {
            for (int b = 0; b <= limit; b++) {
                int c = n - a - b;
                if (c >= 0 && c <= limit) count++;
            }
        }
        return count;
    }
};
