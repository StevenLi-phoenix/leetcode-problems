// @leetcode id=2108 questionId=2231 slug=find-first-palindromic-string-in-the-array lang=cpp site=leetcode.com title="Find First Palindromic String in the Array"
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word == rev) {
                return word;
            }
        }
        return "";
    }
};
