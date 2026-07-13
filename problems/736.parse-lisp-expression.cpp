// @leetcode id=736 questionId=736 slug=parse-lisp-expression lang=cpp site=leetcode.com title="Parse Lisp Expression"
class Solution {
public:
    int evaluate(string expression) {
        vector<unordered_map<string, long long>> scopes;
        return (int)eval(expression, scopes);
    }

private:
    // Splits the content between an expression's outer parens into
    // top-level tokens (space-separated, respecting nested parens).
    vector<string> tokenize(const string& s) {
        vector<string> tokens;
        int n = s.size(), i = 0;
        while (i < n) {
            if (s[i] == ' ') { i++; continue; }
            if (s[i] == '(') {
                int depth = 0, start = i;
                while (i < n) {
                    if (s[i] == '(') depth++;
                    else if (s[i] == ')') depth--;
                    i++;
                    if (depth == 0) break;
                }
                tokens.push_back(s.substr(start, i - start));
            } else {
                int start = i;
                while (i < n && s[i] != ' ') i++;
                tokens.push_back(s.substr(start, i - start));
            }
        }
        return tokens;
    }

    long long eval(const string& expr, vector<unordered_map<string, long long>>& scopes) {
        if (expr[0] != '(') {
            if (isdigit(expr[0]) || expr[0] == '-') return stoll(expr);
            // Variable lookup: innermost scope first.
            for (int i = scopes.size() - 1; i >= 0; i--) {
                auto it = scopes[i].find(expr);
                if (it != scopes[i].end()) return it->second;
            }
            return 0;
        }

        vector<string> tokens = tokenize(expr.substr(1, expr.size() - 2));
        const string& op = tokens[0];
        if (op == "add") {
            return eval(tokens[1], scopes) + eval(tokens[2], scopes);
        }
        if (op == "mult") {
            return eval(tokens[1], scopes) * eval(tokens[2], scopes);
        }
        // "let": assignments are evaluated sequentially in a fresh scope
        // that's visible to later assignments and the final expression.
        scopes.push_back({});
        long long result = 0;
        for (int i = 1; i < (int)tokens.size(); i += 2) {
            if (i == (int)tokens.size() - 1) {
                result = eval(tokens[i], scopes);
                break;
            }
            scopes.back()[tokens[i]] = eval(tokens[i + 1], scopes);
        }
        scopes.pop_back();
        return result;
    }
};
