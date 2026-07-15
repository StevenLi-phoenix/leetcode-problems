// @leetcode id=3746 questionId=4090 slug=minimum-string-length-after-balanced-removals lang=cpp site=leetcode.com title="Minimum String Length After Balanced Removals"
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA = 0, countB = 0;
        for (char c : s) {
            if (c == 'a') countA++;
            else countB++;
        }
        return abs(countA - countB);
    }
};
