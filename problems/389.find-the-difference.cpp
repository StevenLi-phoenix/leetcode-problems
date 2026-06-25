// @leetcode id=389 questionId=389 slug=find-the-difference lang=cpp site=leetcode.com title="Find the Difference"
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (char c : s) result ^= c;
        for (char c : t) result ^= c;
        return result;
    }
};
