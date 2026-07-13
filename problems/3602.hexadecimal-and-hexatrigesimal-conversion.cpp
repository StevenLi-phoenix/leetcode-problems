// @leetcode id=3602 questionId=3912 slug=hexadecimal-and-hexatrigesimal-conversion lang=cpp site=leetcode.com title="Hexadecimal and Hexatrigesimal Conversion"
class Solution {
public:
    string concatHex36(int n) {
        auto toBase = [](long long x, int base) {
            const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            if (x == 0) return string("0");
            string s;
            while (x > 0) {
                s += digits[x % base];
                x /= base;
            }
            reverse(s.begin(), s.end());
            return s;
        };

        long long sq = (long long)n * n;
        long long cube = sq * n;
        return toBase(sq, 16) + toBase(cube, 36);
    }
};
