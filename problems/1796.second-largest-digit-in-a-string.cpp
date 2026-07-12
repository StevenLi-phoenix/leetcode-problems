// @leetcode id=1796 questionId=1904 slug=second-largest-digit-in-a-string lang=cpp site=leetcode.com title="Second Largest Digit in a String"
class Solution {
public:
    int secondHighest(string s) {
        bool seen[10] = {};
        for (char c : s)
            if (isdigit(c)) seen[c - '0'] = true;

        int count = 0;
        for (int d = 9; d >= 0; d--) {
            if (seen[d]) {
                count++;
                if (count == 2) return d;
            }
        }
        return -1;
    }
};
