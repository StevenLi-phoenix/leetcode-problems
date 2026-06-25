// @leetcode id=357 questionId=357 slug=count-numbers-with-unique-digits lang=cpp site=leetcode.com title="Count Numbers with Unique Digits"
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int result = 10;
        int uniqueDigits = 9;
        int availableDigits = 9;
        for (int i = 2; i <= n && availableDigits > 0; i++) {
            uniqueDigits *= availableDigits;
            result += uniqueDigits;
            availableDigits--;
        }
        return result;
    }
};
