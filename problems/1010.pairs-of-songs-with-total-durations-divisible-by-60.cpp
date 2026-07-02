// @leetcode id=1010 questionId=1055 slug=pairs-of-songs-with-total-durations-divisible-by-60 lang=cpp site=leetcode.com title="Pairs of Songs With Total Durations Divisible by 60"
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60] = {0};
        long long total = 0;
        for (int t : time) {
            int r = t % 60;
            int need = (60 - r) % 60;
            total += count[need];
            count[r]++;
        }
        return total;
    }
};
