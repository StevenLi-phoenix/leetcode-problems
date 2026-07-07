// @leetcode id=537 questionId=537 slug=complex-number-multiplication lang=cpp site=leetcode.com title="Complex Number Multiplication"
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto parse = [](const string& s) -> pair<int, int> {
            int plusPos = s.find('+', 1); // skip a possible leading '-'
            int real = stoi(s.substr(0, plusPos));
            int imag = stoi(s.substr(plusPos + 1, s.size() - plusPos - 2));
            return {real, imag};
        };

        auto [a, b] = parse(num1);
        auto [c, d] = parse(num2);

        int real = a * c - b * d;
        int imag = a * d + b * c;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};
