// @leetcode id=3120 questionId=3408 slug=count-the-number-of-special-characters-i lang=cpp site=leetcode.com title="Count the Number of Special Characters I"
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> lower;
        for (char c : word) {
            if (c >= 'a' && c <= 'z') lower.insert(c);
        }
        set<char> result;
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                char lc = c - 'A' + 'a';
                if (lower.count(lc)) result.insert(lc);
            }
        }
        return result.size();
    }
};
