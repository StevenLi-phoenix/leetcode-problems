// @leetcode id=458 questionId=458 slug=poor-pigs lang=cpp site=leetcode.com title="Poor Pigs"
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        int pigs = 0;
        long long capacity = 1;
        while (capacity < buckets) {
            capacity *= (rounds + 1);
            pigs++;
        }
        return pigs;
    }
};
