// @leetcode id=1627 questionId=1223 slug=graph-connectivity-with-threshold lang=cpp site=leetcode.com title="Graph Connectivity With Threshold"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);

        for (int z = threshold + 1; z <= n; z++) {
            for (int m = 2 * z; m <= n; m += z) {
                unite(z, m);
            }
        }

        vector<bool> answer;
        answer.reserve(queries.size());
        for (auto& q : queries) {
            answer.push_back(find(q[0]) == find(q[1]));
        }
        return answer;
    }
};
