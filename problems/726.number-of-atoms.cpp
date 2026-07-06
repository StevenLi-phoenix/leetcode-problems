// @leetcode id=726 questionId=726 slug=number-of-atoms lang=cpp site=leetcode.com title="Number of Atoms"
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = 0;
        vector<map<string, long long>> stk;
        stk.push_back({});

        while (i < n) {
            char c = formula[i];
            if (c == '(') {
                stk.push_back({});
                ++i;
            } else if (c == ')') {
                ++i;
                int start = i;
                while (i < n && isdigit(formula[i])) ++i;
                long long mult = (i > start) ? stoll(formula.substr(start, i - start)) : 1;

                map<string, long long> top = stk.back();
                stk.pop_back();
                for (auto& [name, cnt] : top) {
                    stk.back()[name] += cnt * mult;
                }
            } else {
                int start = i;
                ++i;
                while (i < n && islower(formula[i])) ++i;
                string name = formula.substr(start, i - start);

                int numStart = i;
                while (i < n && isdigit(formula[i])) ++i;
                long long cnt = (i > numStart) ? stoll(formula.substr(numStart, i - numStart)) : 1;

                stk.back()[name] += cnt;
            }
        }

        string result;
        for (auto& [name, cnt] : stk.back()) {
            result += name;
            if (cnt > 1) result += to_string(cnt);
        }
        return result;
    }
};
