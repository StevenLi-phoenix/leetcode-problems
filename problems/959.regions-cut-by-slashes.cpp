// @leetcode id=959 questionId=999 slug=regions-cut-by-slashes lang=cpp site=leetcode.com title="Regions Cut By Slashes"
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int total = n * n * 4;
        vector<int> parent(total);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        auto idx = [&](int r, int c, int t) {
            return (r * n + c) * 4 + t; // t: 0=top,1=right,2=bottom,3=left
        };

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                char ch = grid[r][c];
                int top = idx(r, c, 0), right = idx(r, c, 1), bottom = idx(r, c, 2), left = idx(r, c, 3);

                if (ch == ' ') {
                    unite(top, right);
                    unite(right, bottom);
                    unite(bottom, left);
                } else if (ch == '/') {
                    unite(top, left);
                    unite(right, bottom);
                } else { // '\'
                    unite(top, right);
                    unite(bottom, left);
                }

                if (c + 1 < n) unite(right, idx(r, c + 1, 3));
                if (r + 1 < n) unite(bottom, idx(r + 1, c, 0));
            }
        }

        int count = 0;
        for (int i = 0; i < total; ++i) {
            if (find(i) == i) ++count;
        }
        return count;
    }
};
