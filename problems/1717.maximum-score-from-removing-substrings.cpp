// @leetcode id=1717 questionId=1818 slug=maximum-score-from-removing-substrings lang=cpp site=leetcode.com title="Maximum Score From Removing Substrings"
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first = 'a', second = 'b';
        int firstScore = x, secondScore = y;
        if (y > x) {
            swap(first, second);
            swap(firstScore, secondScore);
        }

        int total = 0;
        string stack;
        for (char c : s) {
            if (c == second && !stack.empty() && stack.back() == first) {
                stack.pop_back();
                total += firstScore;
            } else {
                stack.push_back(c);
            }
        }

        string stack2;
        for (char c : stack) {
            if (c == first && !stack2.empty() && stack2.back() == second) {
                stack2.pop_back();
                total += secondScore;
            } else {
                stack2.push_back(c);
            }
        }

        return total;
    }
};
