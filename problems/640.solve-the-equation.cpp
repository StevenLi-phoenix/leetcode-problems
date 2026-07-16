// @leetcode id=640 questionId=640 slug=solve-the-equation lang=cpp site=leetcode.com title="Solve the Equation"
class Solution {
public:
    string solveEquation(string equation) {
        int eqPos = equation.find('=');
        string left = equation.substr(0, eqPos);
        string right = equation.substr(eqPos + 1);

        auto parse = [](const string& s, int& coeff, int& constant) {
            coeff = 0;
            constant = 0;
            int i = 0;
            int n = s.size();
            while (i < n) {
                int sign = 1;
                if (s[i] == '+') i++;
                else if (s[i] == '-') { sign = -1; i++; }

                int start = i;
                while (i < n && isdigit(s[i])) i++;
                bool hasNum = i > start;
                int num = hasNum ? stoi(s.substr(start, i - start)) : 1;

                if (i < n && s[i] == 'x') {
                    coeff += sign * num;
                    i++;
                } else {
                    constant += sign * num;
                }
            }
        };

        int lc, lk, rc, rk;
        parse(left, lc, lk);
        parse(right, rc, rk);

        int coeff = lc - rc;
        int constant = rk - lk;

        if (coeff == 0) {
            if (constant == 0) return "Infinite solutions";
            return "No solution";
        }
        return "x=" + to_string(constant / coeff);
    }
};
