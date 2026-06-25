// @leetcode id=1641 questionId=1761 slug=count-sorted-vowel-strings lang=cpp site=leetcode.com title="Count Sorted Vowel Strings"
class Solution {
public:
    int countVowelStrings(int n) {
        // Stars and bars: C(n+4, 4) = (n+1)(n+2)(n+3)(n+4) / 24
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};
