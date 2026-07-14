// @leetcode id=3517 questionId=3812 slug=smallest-palindromic-rearrangement-i lang=cpp site=leetcode.com title="Smallest Palindromic Rearrangement I"
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        string half;
        char mid = 0;
        for (int c = 0; c < 26; c++) {
            half += string(count[c] / 2, 'a' + c);
            if (count[c] % 2 == 1) mid = 'a' + c;
        }

        string result = half;
        if (mid) result += mid;
        string rev = half;
        reverse(rev.begin(), rev.end());
        result += rev;
        return result;
    }
};
