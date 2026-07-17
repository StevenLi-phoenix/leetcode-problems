// @leetcode id=1896 questionId=2008 slug=minimum-cost-to-change-the-final-value-of-expression lang=cpp site=leetcode.com title="Minimum Cost to Change the Final Value of Expression"
class Solution {
public:
    pair<int,int> combine(char op, pair<int,int> l, pair<int,int> r) {
        int l0 = l.first, l1 = l.second, r0 = r.first, r1 = r.second;
        int cost0_and = min(l0, r0);
        int cost1_and = l1 + r1;
        int cost0_or = l0 + r0;
        int cost1_or = min(l1, r1);

        int cost0, cost1;
        if (op == '&') {
            cost0 = min(cost0_and, 1 + cost0_or);
            cost1 = min(cost1_and, 1 + cost1_or);
        } else {
            cost0 = min(cost0_or, 1 + cost0_and);
            cost1 = min(cost1_or, 1 + cost1_and);
        }
        return {cost0, cost1};
    }

    void foldTop(vector<pair<int,int>>& vals, vector<char>& ops) {
        char op = ops.back(); ops.pop_back();
        auto r = vals.back(); vals.pop_back();
        auto l = vals.back(); vals.pop_back();
        vals.push_back(combine(op, l, r));
    }

    int minOperationsToFlip(string expression) {
        vector<pair<int,int>> vals;
        vector<char> ops;

        for (char c : expression) {
            if (c == '0') {
                vals.push_back({0, 1});
            } else if (c == '1') {
                vals.push_back({1, 0});
            } else if (c == '(') {
                ops.push_back('(');
            } else if (c == ')') {
                while (!ops.empty() && ops.back() != '(') foldTop(vals, ops);
                ops.pop_back();
            } else {
                while (!ops.empty() && ops.back() != '(') foldTop(vals, ops);
                ops.push_back(c);
            }
        }

        while (!ops.empty()) foldTop(vals, ops);

        auto final = vals.back();
        return final.first == 0 ? final.second : final.first;
    }
};
