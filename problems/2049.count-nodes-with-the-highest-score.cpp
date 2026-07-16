// @leetcode id=2049 questionId=2175 slug=count-nodes-with-the-highest-score lang=cpp site=leetcode.com title="Count Nodes With the Highest Score"
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> children(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) root = i;
            else children[parents[i]].push_back(i);
        }

        vector<int> order;
        order.reserve(n);
        queue<int> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            order.push_back(u);
            for (int c : children[u]) bfs.push(c);
        }

        vector<long long> size(n, 1);
        for (int i = order.size() - 1; i >= 0; i--) {
            int u = order[i];
            if (parents[u] != -1) size[parents[u]] += size[u];
        }

        long long best = 0;
        int count = 0;
        for (int u = 0; u < n; u++) {
            long long score = 1;
            for (int c : children[u]) score *= size[c];
            long long rest = n - size[u];
            if (rest > 0) score *= rest;

            if (score > best) {
                best = score;
                count = 1;
            } else if (score == best) {
                count++;
            }
        }
        return count;
    }
};
