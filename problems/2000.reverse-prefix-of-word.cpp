// @leetcode id=2000 questionId=2128 slug=reverse-prefix-of-word lang=cpp site=leetcode.com title="Reverse Prefix of Word"
class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t idx = word.find(ch);
        if (idx == string::npos) return word;
        reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};
