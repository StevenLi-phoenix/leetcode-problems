// @leetcode id=972 questionId=1012 slug=equal-rational-numbers lang=cpp site=leetcode.com title="Equal Rational Numbers"
class Solution {
public:
    bool isRationalEqual(string s, string t) {
        auto [n1, d1] = parse(s);
        auto [n2, d2] = parse(t);
        return n1 * d2 == n2 * d1;
    }

private:
    long long ipow10(int e) {
        long long r = 1;
        for (int i = 0; i < e; ++i) r *= 10;
        return r;
    }

    long long toLL(const string& s) {
        return s.empty() ? 0 : stoll(s);
    }

    pair<long long, long long> parse(const string& s) {
        int dot = s.find('.');
        if (dot == (int)string::npos) {
            return {toLL(s), 1};
        }

        string integerPart = s.substr(0, dot);
        string rest = s.substr(dot + 1);
        int paren = rest.find('(');

        long long I = toLL(integerPart);

        if (paren == (int)string::npos) {
            int n = rest.size();
            long long den = ipow10(n);
            long long num = I * den + toLL(rest);
            return {num, den};
        }

        string nonRepeat = rest.substr(0, paren);
        string repeat = rest.substr(paren + 1, rest.size() - paren - 2);

        int n = nonRepeat.size(), r = repeat.size();
        long long N = toLL(nonRepeat);
        long long NR = toLL(nonRepeat + repeat);

        long long fracNum = NR - N;
        long long fracDen = ipow10(n) * (ipow10(r) - 1);

        long long num = I * fracDen + fracNum;
        return {num, fracDen};
    }
};
