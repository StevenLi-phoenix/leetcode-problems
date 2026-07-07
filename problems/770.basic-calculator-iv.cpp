// @leetcode id=770 questionId=781 slug=basic-calculator-iv lang=cpp site=leetcode.com title="Basic Calculator IV"
class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, long long> evalMap;
        for (int i = 0; i < (int)evalvars.size(); ++i) evalMap[evalvars[i]] = evalints[i];

        using Poly = map<vector<string>, long long>;

        string s = expression;
        int pos = 0;
        int n = s.size();

        auto peekChar = [&]() -> char {
            int p = pos;
            while (p < n && s[p] == ' ') ++p;
            return p < n ? s[p] : '\0';
        };

        auto nextToken = [&]() -> string {
            while (pos < n && s[pos] == ' ') ++pos;
            if (pos >= n) return "";
            char c = s[pos];
            if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*') {
                ++pos;
                return string(1, c);
            }
            if (isdigit(c)) {
                int start = pos;
                while (pos < n && isdigit(s[pos])) ++pos;
                return s.substr(start, pos - start);
            }
            int start = pos;
            while (pos < n && isalpha(s[pos])) ++pos;
            return s.substr(start, pos - start);
        };

        auto addPoly = [&](Poly& a, Poly& b, int sign) -> Poly {
            Poly result = a;
            for (auto& [vars, coeff] : b) {
                result[vars] += sign * coeff;
                if (result[vars] == 0) result.erase(vars);
            }
            return result;
        };

        auto mulPoly = [&](Poly& a, Poly& b) -> Poly {
            Poly result;
            for (auto& [varsA, coeffA] : a) {
                for (auto& [varsB, coeffB] : b) {
                    vector<string> merged = varsA;
                    merged.insert(merged.end(), varsB.begin(), varsB.end());
                    sort(merged.begin(), merged.end());
                    result[merged] += coeffA * coeffB;
                    if (result[merged] == 0) result.erase(merged);
                }
            }
            return result;
        };

        function<Poly()> parseExpr;
        function<Poly()> parseTerm;
        function<Poly()> parseFactor;

        parseFactor = [&]() -> Poly {
            if (peekChar() == '(') {
                nextToken();
                Poly result = parseExpr();
                nextToken(); // consume ')'
                return result;
            }
            string tok = nextToken();
            Poly p;
            if (isdigit(tok[0])) {
                p[{}] = stoll(tok);
            } else if (evalMap.count(tok)) {
                p[{}] = evalMap[tok];
            } else {
                p[{tok}] = 1;
            }
            return p;
        };

        parseTerm = [&]() -> Poly {
            Poly result = parseFactor();
            while (peekChar() == '*') {
                nextToken();
                Poly rhs = parseFactor();
                result = mulPoly(result, rhs);
            }
            return result;
        };

        parseExpr = [&]() -> Poly {
            Poly result = parseTerm();
            while (peekChar() == '+' || peekChar() == '-') {
                string op = nextToken();
                Poly rhs = parseTerm();
                result = addPoly(result, rhs, op == "+" ? 1 : -1);
            }
            return result;
        };

        Poly final = parseExpr();

        vector<pair<vector<string>, long long>> terms;
        for (auto& [vars, coeff] : final) {
            if (coeff != 0) terms.push_back({vars, coeff});
        }
        sort(terms.begin(), terms.end(), [](const auto& a, const auto& b) {
            if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
            return a.first < b.first;
        });

        vector<string> result;
        for (auto& [vars, coeff] : terms) {
            string term = to_string(coeff);
            for (auto& v : vars) term += "*" + v;
            result.push_back(term);
        }
        return result;
    }
};
