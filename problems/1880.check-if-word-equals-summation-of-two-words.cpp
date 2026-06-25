// @leetcode id=1880 questionId=2010 slug=check-if-word-equals-summation-of-two-words lang=cpp site=leetcode.com title="Check if Word Equals Summation of Two Words"
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto toNum = [](const string& s) {
            int val = 0;
            for (char c : s) val = val * 10 + (c - 'a');
            return val;
        };
        return toNum(firstWord) + toNum(secondWord) == toNum(targetWord);
    }
};
