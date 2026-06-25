// @leetcode id=1970 questionId=2101 slug=last-day-where-you-can-still-cross lang=cpp site=leetcode.com title="Last Day Where You Can Still Cross"
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        vector<int> p, sz;
        DSU(int n) : p(n), sz(n, 1) {
            iota(p.begin(), p.end(), 0);
        }
        int find(int x) {
            while (p[x] != x) {
                p[x] = p[p[x]];
                x = p[x];
            }
            return x;
        }
        void unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        }
        bool same(int a, int b) { return find(a) == find(b); }
    };

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n, BOTTOM = n + 1;
        DSU dsu(n + 2);

        vector<char> active(n, 0); 

        auto id = [&](int r, int c) { // r,c are 0-based
            return r * col + c;
        };

        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        for (int i = n - 1; i >= 0; --i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            int cur = id(r, c);

            active[cur] = 1;

            if (r == 0) dsu.unite(cur, TOP);
            if (r == row - 1) dsu.unite(cur, BOTTOM);

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                int nei = id(nr, nc);
                if (active[nei]) dsu.unite(cur, nei);
            }

            if (dsu.same(TOP, BOTTOM)) return i; 
        }

        return 0; 
    }
};
