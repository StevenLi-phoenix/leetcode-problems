// @leetcode id=1529 questionId=1652 slug=minimum-suffix-flips lang=cpp site=leetcode.com title="Minimum Suffix Flips"
class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        char prev = '0';
        for (char c : target) {
            if (c != prev) count++;
            prev = c;
        }
        return count;
    }
};
