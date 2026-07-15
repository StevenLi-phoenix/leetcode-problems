// @leetcode id=3331 questionId=3576 slug=find-subtree-sizes-after-changes lang=cpp site=leetcode.com title="Find Subtree Sizes After Changes"
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(n, -1);
        vector<vector<int>> charStack(26);

        // Iterative DFS: state 0 = enter, state 1 = exit.
        vector<pair<int, int>> stack;
        stack.push_back({0, 0});
        while (!stack.empty()) {
            auto [u, state] = stack.back();
            stack.pop_back();
            int c = s[u] - 'a';
            if (state == 0) {
                if (u != 0) {
                    if (!charStack[c].empty()) newParent[u] = charStack[c].back();
                    else newParent[u] = parent[u];
                }
                charStack[c].push_back(u);
                stack.push_back({u, 1});
                for (int v : children[u]) stack.push_back({v, 0});
            } else {
                charStack[c].pop_back();
            }
        }

        vector<vector<int>> newChildren(n);
        for (int i = 1; i < n; i++) newChildren[newParent[i]].push_back(i);

        // Iterative post-order to compute subtree sizes.
        vector<int> order;
        order.reserve(n);
        vector<int> dfsStack = {0};
        while (!dfsStack.empty()) {
            int u = dfsStack.back();
            dfsStack.pop_back();
            order.push_back(u);
            for (int v : newChildren[u]) dfsStack.push_back(v);
        }

        vector<int> size(n, 1);
        for (int i = (int)order.size() - 1; i > 0; i--) {
            int u = order[i];
            size[newParent[u]] += size[u];
        }

        return size;
    }
};
