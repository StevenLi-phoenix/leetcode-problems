// @leetcode id=2157 questionId=2276 slug=groups-of-strings lang=cpp site=leetcode.com title="Groups of Strings"
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

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> maskCount;
        for (auto& w : words) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            maskCount[mask]++;
        }

        vector<int> masks;
        unordered_map<int, int> maskToIdx;
        for (auto& [m, c] : maskCount) {
            maskToIdx[m] = masks.size();
            masks.push_back(m);
        }

        int distinctCount = masks.size();
        parent.resize(distinctCount);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < distinctCount; i++) {
            int m = masks[i];

            // add one bit
            for (int b = 0; b < 26; b++) {
                if (!(m & (1 << b))) {
                    int nm = m | (1 << b);
                    auto it = maskToIdx.find(nm);
                    if (it != maskToIdx.end()) unite(i, it->second);
                }
            }

            // replace: remove one bit, add a different one
            for (int r = 0; r < 26; r++) {
                if (!(m & (1 << r))) continue;
                int base = m & ~(1 << r);
                for (int a = 0; a < 26; a++) {
                    if (a == r || (m & (1 << a))) continue;
                    int nm = base | (1 << a);
                    auto it = maskToIdx.find(nm);
                    if (it != maskToIdx.end()) unite(i, it->second);
                }
            }
        }

        unordered_map<int, long long> componentSize;
        for (int i = 0; i < distinctCount; i++) {
            int root = find(i);
            componentSize[root] += maskCount[masks[i]];
        }

        long long maxSize = 0;
        for (auto& [root, sz] : componentSize) maxSize = max(maxSize, sz);

        return {(int)componentSize.size(), (int)maxSize};
    }
};
