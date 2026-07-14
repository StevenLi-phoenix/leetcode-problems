// @leetcode id=409 questionId=409 slug=longest-palindrome lang=cpp site=leetcode.com title="Longest Palindrome"
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;

        int length = 0;
        bool hasOdd = false;
        for (auto& [c, n] : count) {
            length += (n / 2) * 2;
            if (n % 2 == 1) hasOdd = true;
        }
        return length + (hasOdd ? 1 : 0);
    }
};
