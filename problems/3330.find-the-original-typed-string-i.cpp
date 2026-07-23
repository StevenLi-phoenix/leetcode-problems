// @leetcode id=3330 questionId=3617 slug=find-the-original-typed-string-i lang=cpp site=leetcode.com title="Find the Original Typed String I"
class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int runs = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] != word[i - 1]) runs++;
        }
        return 1 + (n - runs);
    }
};
