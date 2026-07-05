// @leetcode id=547 questionId=547 slug=number-of-provinces lang=cpp site=leetcode.com title="Number of Provinces"
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    int ri = find(i), rj = find(j);
                    if (ri != rj) parent[ri] = rj;
                }
            }
        }

        unordered_set<int> roots;
        for (int i = 0; i < n; ++i) roots.insert(find(i));
        return roots.size();
    }
};
