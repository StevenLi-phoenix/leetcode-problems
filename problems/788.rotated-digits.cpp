// @leetcode id=788 questionId=804 slug=rotated-digits lang=cpp site=leetcode.com title="Rotated Digits"
class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) count++;
        }
        return count;
    }
    
    bool isGood(int num) {
        bool different = false;
        while (num > 0) {
            int d = num % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) different = true;
            num /= 10;
        }
        return different;
    }
};
