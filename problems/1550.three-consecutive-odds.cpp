// @leetcode id=1550 questionId=1293 slug=three-consecutive-odds lang=cpp site=leetcode.com title="Three Consecutive Odds"
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int x : arr) {
            if (x % 2 != 0) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0;
            }
        }
        return false;
    }
};
