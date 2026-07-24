// @leetcode id=3232 questionId=3515 slug=find-if-digit-game-can-be-won lang=cpp site=leetcode.com title="Find if Digit Game Can Be Won"
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0, dbl = 0;
        for (int x : nums) {
            if (x < 10) single += x;
            else dbl += x;
        }
        return single != dbl;
    }
};
