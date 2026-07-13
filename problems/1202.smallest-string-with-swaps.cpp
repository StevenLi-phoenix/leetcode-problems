// @leetcode id=1202 questionId=1308 slug=smallest-string-with-swaps lang=cpp site=leetcode.com title="Smallest String With Swaps"
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        for (auto& p : pairs) {
            int ra = find(p[0]), rb = find(p[1]);
            if (ra != rb) parent[ra] = rb;
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[find(i)].push_back(i);

        string res = s;
        for (auto& [root, indices] : groups) {
            vector<int> sortedIdx = indices;
            sort(sortedIdx.begin(), sortedIdx.end());
            string chars;
            for (int idx : sortedIdx) chars += s[idx];
            sort(chars.begin(), chars.end());
            for (size_t k = 0; k < sortedIdx.size(); k++) res[sortedIdx[k]] = chars[k];
        }
        return res;
    }
};
