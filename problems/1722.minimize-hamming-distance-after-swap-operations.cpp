// @leetcode id=1722 questionId=1840 slug=minimize-hamming-distance-after-swap-operations lang=cpp site=leetcode.com title="Minimize Hamming Distance After Swap Operations"
class Solution {
    public:
    int find(vector<int>& parent, int x) {
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
    }
    void unite(vector<int>& parent, int a, int b) {
    int pa = find(parent, a), pb = find(parent, b);
    if (pa != pb) parent[pa] = pb;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int n = source.size();
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    for (auto& s : allowedSwaps) {
    unite(parent, s[0], s[1]);
    }
    unordered_map<int, unordered_map<int,int>> groups;
    for (int i = 0; i < n; i++) {
    groups[find(parent, i)][source[i]]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
    int root = find(parent, i);
    auto& freq = groups[root];
    if (freq.count(target[i]) && freq[target[i]] > 0) {
    freq[target[i]]--;
    } else {
    res++;
    }
    }
    return res;
    }
    };
