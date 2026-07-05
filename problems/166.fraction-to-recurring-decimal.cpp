// @leetcode id=166 questionId=166 slug=fraction-to-recurring-decimal lang=cpp site=leetcode.com title="Fraction to Recurring Decimal"
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator, den = denominator;
        if (num == 0) return "0";

        string result;
        if ((num < 0) != (den < 0)) result += "-";
        num = llabs(num);
        den = llabs(den);

        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return result;

        result += ".";
        unordered_map<long long, int> seen;
        string frac;
        while (rem != 0) {
            if (seen.count(rem)) {
                frac.insert(seen[rem], "(");
                frac += ")";
                break;
            }
            seen[rem] = frac.size();
            rem *= 10;
            frac += to_string(rem / den);
            rem %= den;
        }
        return result + frac;
    }
};
