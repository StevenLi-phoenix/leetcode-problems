// @leetcode id=592 questionId=592 slug=fraction-addition-and-subtraction lang=cpp site=leetcode.com title="Fraction Addition and Subtraction"
class Solution {
public:
    string fractionAddition(string expression) {
        long long num = 0, den = 1;
        int i = 0, n = expression.size();
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+') { i++; }
            else if (expression[i] == '-') { sign = -1; i++; }

            long long curNum = 0;
            while (i < n && isdigit(expression[i])) {
                curNum = curNum * 10 + (expression[i] - '0');
                i++;
            }
            curNum *= sign;
            i++; // skip '/'

            long long curDen = 0;
            while (i < n && isdigit(expression[i])) {
                curDen = curDen * 10 + (expression[i] - '0');
                i++;
            }

            num = num * curDen + curNum * den;
            den = den * curDen;

            long long g = gcd(abs(num), den);
            if (g > 0) {
                num /= g;
                den /= g;
            }
        }

        if (num == 0) den = 1;
        return to_string(num) + "/" + to_string(den);
    }

private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};
