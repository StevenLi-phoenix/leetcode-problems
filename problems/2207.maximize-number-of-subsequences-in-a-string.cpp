// @leetcode id=2207 questionId=2309 slug=maximize-number-of-subsequences-in-a-string lang=cpp site=leetcode.com title="Maximize Number of Subsequences in a String"
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char p0 = pattern[0], p1 = pattern[1];
        long long base = 0;
        long long countP0 = 0, countP1 = 0;

        for (char c : text) {
            if (c == p1) {
                base += countP0;
                countP1++;
            }
            if (c == p0) {
                countP0++;
            }
        }

        long long candidate1 = base + countP1;
        long long candidate2 = base + countP0;
        return max(candidate1, candidate2);
    }
};
