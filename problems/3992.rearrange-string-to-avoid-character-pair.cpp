// @leetcode id=3992 questionId=4355 slug=rearrange-string-to-avoid-character-pair lang=cpp site=leetcode.com title="Rearrange String to Avoid Character Pair"
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys, xs, others;
        for (char c : s) {
            if (c == y) ys += c;
            else if (c == x) xs += c;
            else others += c;
        }
        return ys + others + xs;
    }
};
