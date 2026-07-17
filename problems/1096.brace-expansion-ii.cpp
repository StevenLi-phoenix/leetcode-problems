// @leetcode id=1096 questionId=1188 slug=brace-expansion-ii lang=cpp site=leetcode.com title="Brace Expansion II"
class Solution {
public:
    string s;
    size_t pos;

    set<string> parseTerm() {
        if (s[pos] == '{') {
            pos++;
            set<string> r = parseUnion();
            pos++; // consume '}'
            return r;
        } else {
            string letter(1, s[pos]);
            pos++;
            return {letter};
        }
    }

    set<string> parseConcat() {
        vector<set<string>> factors;
        while (pos < s.size() && s[pos] != ',' && s[pos] != '}') {
            factors.push_back(parseTerm());
        }

        set<string> result = {""};
        for (auto& f : factors) {
            set<string> next;
            for (auto& a : result) {
                for (auto& b : f) next.insert(a + b);
            }
            result = next;
        }
        return result;
    }

    set<string> parseUnion() {
        set<string> result = parseConcat();
        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> part = parseConcat();
            result.insert(part.begin(), part.end());
        }
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> result = parseUnion();
        return vector<string>(result.begin(), result.end());
    }
};
