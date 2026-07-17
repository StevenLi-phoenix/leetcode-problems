// @leetcode id=947 questionId=984 slug=most-stones-removed-with-same-row-or-column lang=cpp site=leetcode.com title="Most Stones Removed with Same Row or Column"
class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    int removeStones(vector<vector<int>>& stones) {
        for (auto& s : stones) {
            unite(s[0], ~s[1]);
        }

        unordered_set<int> roots;
        for (auto& s : stones) {
            roots.insert(find(s[0]));
        }
        return (int)stones.size() - (int)roots.size();
    }
};
