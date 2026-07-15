// @leetcode id=650 questionId=650 slug=2-keys-keyboard lang=cpp site=leetcode.com title="2 Keys Keyboard"
class Solution {
public:
    int minSteps(int n) {
        int result = 0;
        for (int factor = 2; factor <= n; factor++) {
            while (n % factor == 0) {
                result += factor;
                n /= factor;
            }
        }
        return result;
    }
};
