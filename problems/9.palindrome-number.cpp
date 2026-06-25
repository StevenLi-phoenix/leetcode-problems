// @leetcode id=9 questionId=9 slug=palindrome-number lang=cpp site=leetcode.com title="Palindrome Number"
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;

        int revHalf = 0;
        while (x > revHalf) {
            int digit = x % 10;
            revHalf = revHalf * 10 + digit;
            x /= 10;
        }

        // For even length: x == revHalf
        // For odd length:  x == revHalf/10 (middle digit ignored)
        return (x == revHalf) || (x == revHalf / 10);
    }
};
