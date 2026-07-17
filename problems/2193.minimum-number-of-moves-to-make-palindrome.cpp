// @leetcode id=2193 questionId=1356 slug=minimum-number-of-moves-to-make-palindrome lang=cpp site=leetcode.com title="Minimum Number of Moves to Make Palindrome"
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int moves = 0;
        int left = 0, right = s.size() - 1;

        while (left < right) {
            int j = right;
            while (j > left && s[j] != s[left]) j--;

            if (j == left) {
                // s[left] is the lone middle-ish character; swap it one step to the right
                swap(s[left], s[left + 1]);
                moves++;
            } else {
                for (int k = j; k < right; k++) {
                    swap(s[k], s[k + 1]);
                    moves++;
                }
                left++;
                right--;
            }
        }

        return moves;
    }
};
