// @leetcode id=1374 questionId=1490 slug=generate-a-string-with-characters-that-have-odd-counts lang=cpp site=leetcode.com title="Generate a String With Characters That Have Odd Counts"
class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 1) return string(n, 'a');
        return string(n - 1, 'a') + "b";
    }
};
