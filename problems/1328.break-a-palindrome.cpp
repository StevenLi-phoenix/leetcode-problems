// @leetcode id=1328 questionId=1252 slug=break-a-palindrome lang=cpp site=leetcode.com title="Break a Palindrome"
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";

        string result = palindrome;
        for (int i = 0; i < n / 2; i++) {
            if (result[i] != 'a') {
                result[i] = 'a';
                return result;
            }
        }
        result[n - 1] = 'b';
        return result;
    }
};
