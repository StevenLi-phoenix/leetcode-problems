// @leetcode id=1963 questionId=2095 slug=minimum-number-of-swaps-to-make-the-string-balanced lang=cpp site=leetcode.com title="Minimum Number of Swaps to Make the String Balanced"
class Solution {
public:
    int minSwaps(string s) {
        // Track balance treating '[' as +1, ']' as -1; the most negative it
        // ever gets is the max simultaneous unmatched close-brackets. Each
        // swap fixes two such excess closes at once.
        int balance = 0, maxDeficit = 0;
        for (char c : s) {
            balance += (c == '[') ? 1 : -1;
            maxDeficit = max(maxDeficit, -balance);
        }
        return (maxDeficit + 1) / 2;
    }
};
