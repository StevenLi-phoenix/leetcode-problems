// @leetcode id=2443 questionId=2541 slug=sum-of-number-and-its-reverse lang=cpp site=leetcode.com title="Sum of Number and Its Reverse"
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; x++) {
            int r = reverse(x);
            if (x + r == num) return true;
        }
        return false;
    }

private:
    int reverse(int x) {
        int result = 0;
        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};
