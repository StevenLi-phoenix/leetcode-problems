// @leetcode id=1697 questionId=1815 slug=checking-existence-of-edge-length-limited-paths lang=cpp site=leetcode.com title="Checking Existence of Edge Length Limited Paths"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][2] < queries[b][2];
        });

        vector<bool> answer(q);
        int edgeIdx = 0;
        int m = edgeList.size();

        for (int idx : order) {
            int p = queries[idx][0], qq = queries[idx][1], limit = queries[idx][2];
            while (edgeIdx < m && edgeList[edgeIdx][2] < limit) {
                unite(edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
                edgeIdx++;
            }
            answer[idx] = (find(p) == find(qq));
        }

        return answer;
    }
};
