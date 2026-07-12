// @leetcode id=3185 questionId=3418 slug=count-pairs-that-form-a-complete-day-ii lang=cpp site=leetcode.com title="Count Pairs That Form a Complete Day II"
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count[24] = {};
        long long total = 0;
        for (int h : hours) {
            int r = h % 24;
            int need = (24 - r) % 24;
            total += count[need];
            count[r]++;
        }
        return total;
    }
};
