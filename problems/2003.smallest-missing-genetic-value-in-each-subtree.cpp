// @leetcode id=2003 questionId=2131 slug=smallest-missing-genetic-value-in-each-subtree lang=cpp site=leetcode.com title="Smallest Missing Genetic Value in Each Subtree"
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) children[parents[i]].push_back(i);

        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) { start = i; break; }
        }

        vector<int> ans(n, 1);
        if (start == -1) return ans;

        vector<int> path;
        for (int cur = start; cur != -1; cur = parents[cur]) path.push_back(cur);
        unordered_set<int> onPath(path.begin(), path.end());

        vector<int> dsu(n + 2);
        iota(dsu.begin(), dsu.end(), 0);
        function<int(int)> findFree = [&](int x) {
            while (dsu[x] != x) { dsu[x] = dsu[dsu[x]]; x = dsu[x]; }
            return x;
        };
        auto markUsed = [&](int v) {
            if (v >= 1 && v <= n + 1) {
                int r = findFree(v);
                dsu[r] = r + 1;
            }
        };

        vector<int> stack;
        auto collectSubtree = [&](int root) {
            stack.push_back(root);
            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                markUsed(nums[node]);
                for (int c : children[node]) stack.push_back(c);
            }
        };

        for (int node : path) {
            markUsed(nums[node]);
            for (int c : children[node]) {
                if (!onPath.count(c)) collectSubtree(c);
            }
            ans[node] = findFree(1);
        }

        return ans;
    }
};
