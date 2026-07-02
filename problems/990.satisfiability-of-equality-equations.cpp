// @leetcode id=990 questionId=1032 slug=satisfiability-of-equality-equations lang=cpp site=leetcode.com title="Satisfiability of Equality Equations"
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int a = find(eq[0] - 'a'), b = find(eq[3] - 'a');
                parent[a] = b;
            }
        }
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                if (find(eq[0] - 'a') == find(eq[3] - 'a')) return false;
            }
        }
        return true;
    }
};
