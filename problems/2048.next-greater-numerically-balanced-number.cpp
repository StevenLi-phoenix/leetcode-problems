// @leetcode id=2048 questionId=2174 slug=next-greater-numerically-balanced-number lang=cpp site=leetcode.com title="Next Greater Numerically Balanced Number"
class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int x = n + 1; ; ++x) {
            if (isBalanced(x)) return x;
        }
    }

private:
    bool isBalanced(int x) {
        int freq[10] = {0};
        for (int t = x; t > 0; t /= 10) freq[t % 10]++;
        for (int d = 0; d < 10; ++d) {
            if (freq[d] != 0 && freq[d] != d) return false;
        }
        return true;
    }
};
