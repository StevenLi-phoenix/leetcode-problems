// @leetcode id=2224 questionId=2345 slug=minimum-number-of-operations-to-convert-time lang=cpp site=leetcode.com title="Minimum Number of Operations to Convert Time"
class Solution {
public:
    int convertTime(string current, string correct) {
        int ch = stoi(current.substr(0, 2)), cm = stoi(current.substr(3, 2));
        int gh = stoi(correct.substr(0, 2)), gm = stoi(correct.substr(3, 2));
        int diff = (gh * 60 + gm) - (ch * 60 + cm);
        int ops = 0;
        for (int x : {60, 15, 5, 1}) {
            ops += diff / x;
            diff %= x;
        }
        return ops;
    }
};
