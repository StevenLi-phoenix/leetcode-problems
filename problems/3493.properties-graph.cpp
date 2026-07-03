// @leetcode id=3493 questionId=3809 slug=properties-graph lang=cpp site=leetcode.com title="Properties Graph"
class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; ++i) {
            sets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
        }

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int common = 0;
                for (int v : sets[i]) {
                    if (sets[j].count(v)) ++common;
                }
                if (common >= k) unite(i, j);
            }
        }

        unordered_set<int> roots;
        for (int i = 0; i < n; ++i) roots.insert(find(i));
        return roots.size();
    }
};
