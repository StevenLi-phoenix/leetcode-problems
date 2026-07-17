// @leetcode id=479 questionId=479 slug=largest-palindrome-product lang=cpp site=leetcode.com title="Largest Palindrome Product"
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long upper = 1;
        for (int i = 0; i < n; i++) upper *= 10;
        upper -= 1;
        long long lower = upper / 10 + 1;

        for (long long half = upper; half >= lower; half--) {
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());
            long long palindrome = stoll(s + rev);

            for (long long x = upper; x * x >= palindrome; x--) {
                if (palindrome % x == 0) {
                    long long y = palindrome / x;
                    if (y <= upper && y >= lower) {
                        return (int)(palindrome % 1337);
                    }
                }
            }
        }
        return -1;
    }
};
