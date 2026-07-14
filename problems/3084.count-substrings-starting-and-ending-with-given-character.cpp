// @leetcode id=3084 questionId=3337 slug=count-substrings-starting-and-ending-with-given-character lang=cpp site=leetcode.com title="Count Substrings Starting and Ending with Given Character"
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long n = count(s.begin(), s.end(), c);
        return n * (n + 1) / 2;
    }
};
