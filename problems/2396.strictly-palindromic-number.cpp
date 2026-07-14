// @leetcode id=2396 questionId=2481 slug=strictly-palindromic-number lang=cpp site=leetcode.com title="Strictly Palindromic Number"
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int b = 2; b <= n - 2; b++) {
            vector<int> digits;
            int x = n;
            while (x > 0) {
                digits.push_back(x % b);
                x /= b;
            }
            int i = 0, j = (int)digits.size() - 1;
            while (i < j) {
                if (digits[i] != digits[j]) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};
