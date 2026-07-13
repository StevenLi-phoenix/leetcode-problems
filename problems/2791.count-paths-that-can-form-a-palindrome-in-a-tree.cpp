// @leetcode id=2791 questionId=2905 slug=count-paths-that-can-form-a-palindrome-in-a-tree lang=cpp site=leetcode.com title="Count Paths That Can Form a Palindrome in a Tree"
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        // Track the XOR-parity bitmask of letter counts from root to each
        // node. A path u-v can be rearranged into a palindrome iff its
        // parity mask (root-to-u XOR root-to-v) has at most one bit set,
        // since a palindrome allows at most one odd-count letter.
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> mask(n, 0);
        vector<int> order;
        order.reserve(n);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : children[u]) {
                mask[v] = mask[u] ^ (1 << (s[v] - 'a'));
                q.push(v);
            }
        }

        unordered_map<int, long long> freq;
        long long ans = 0;
        for (int u : order) {
            int m = mask[u];
            ans += freq[m];
            for (int b = 0; b < 26; b++) ans += freq[m ^ (1 << b)];
            freq[m]++;
        }
        return ans;
    }
};
