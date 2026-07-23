// @leetcode id=1974 questionId=2088 slug=minimum-time-to-type-word-using-special-typewriter lang=cpp site=leetcode.com title="Minimum Time to Type Word Using Special Typewriter"
class Solution {
public:
    int minTimeToType(string word) {
        int total = word.size();
        char cur = 'a';
        for (char c : word) {
            int diff = abs(c - cur);
            total += min(diff, 26 - diff);
            cur = c;
        }
        return total;
    }
};
