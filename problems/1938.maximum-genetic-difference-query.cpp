// @leetcode id=1938 questionId=2068 slug=maximum-genetic-difference-query lang=cpp site=leetcode.com title="Maximum Genetic Difference Query"
class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        // Offline: DFS from root, maintaining a count-trie of the values
        // on the current root-to-node path (insert on entry, remove on
        // exit); answer each node's queries against that trie while it
        // holds exactly the ancestor path.
        int n = parents.size();
        int root = -1;
        vector<vector<int>> children(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) root = i;
            else children[parents[i]].push_back(i);
        }

        vector<vector<pair<int, int>>> queriesAt(n); // (val, queryIdx)
        int q = queries.size();
        for (int i = 0; i < q; i++) queriesAt[queries[i][0]].push_back({queries[i][1], i});

        const int BITS = 18;
        struct TrieNode {
            int child[2] = {-1, -1};
            int count = 0;
        };
        vector<TrieNode> trie(1);

        auto insert = [&](int val, int delta) {
            int node = 0;
            for (int b = BITS - 1; b >= 0; b--) {
                int bit = (val >> b) & 1;
                if (trie[node].child[bit] == -1) {
                    trie[node].child[bit] = trie.size();
                    trie.push_back(TrieNode());
                }
                node = trie[node].child[bit];
                trie[node].count += delta;
            }
        };

        auto queryMax = [&](int val) -> int {
            int node = 0, result = 0;
            for (int b = BITS - 1; b >= 0; b--) {
                int bit = (val >> b) & 1;
                int want = bit ^ 1;
                if (trie[node].child[want] != -1 && trie[trie[node].child[want]].count > 0) {
                    result |= (1 << b);
                    node = trie[node].child[want];
                } else {
                    node = trie[node].child[bit];
                }
            }
            return result;
        };

        vector<int> ans(q);
        vector<pair<int, int>> stack; // (node, nextChildIndex)
        stack.push_back({root, 0});
        insert(root, 1);
        for (auto& [val, idx] : queriesAt[root]) ans[idx] = queryMax(val);

        while (!stack.empty()) {
            int u = stack.back().first;
            int ci = stack.back().second;
            if (ci < (int)children[u].size()) {
                stack.back().second++;
                int v = children[u][ci];
                insert(v, 1);
                for (auto& [val, idx] : queriesAt[v]) ans[idx] = queryMax(val);
                stack.push_back({v, 0});
            } else {
                insert(u, -1);
                stack.pop_back();
            }
        }

        return ans;
    }
};
