// @leetcode id=3454 questionId=3775 slug=separate-squares-ii lang=cpp site=leetcode.com title="Separate Squares II"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long long y, x1, x2;
        int type; // +1 add, -1 remove
        bool operator<(Event const& other) const { return y < other.y; }
    };

    struct SegTree {
        int n; // number of x-segments = xs.size()-1
        vector<int> cover;
        vector<long double> len;
        const vector<long long>* xs;

        SegTree(int n_, const vector<long long>* xs_) : n(n_), xs(xs_) {
            cover.assign(4 * max(1, n), 0);
            len.assign(4 * max(1, n), 0.0L);
        }

        void pull(int node, int l, int r) {
            if (cover[node] > 0) {
                len[node] = (long double)((*xs)[r] - (*xs)[l]);
            } else if (r - l == 1) {
                len[node] = 0.0L;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
            pull(node, l, r);
        }

        void update(int ql, int qr, int val) { // [ql, qr) over segment indices
            if (ql >= qr || n <= 0) return;
            update(1, 0, n, ql, qr, val);
        }

        long double totalLen() const {
            if (n <= 0) return 0.0L;
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        int n = (int)squares.size();
        vector<long long> xs;
        xs.reserve(2LL * n);

        vector<Event> events;
        events.reserve(2LL * n);

        for (auto &sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            long long x2 = x + l, y2 = y + l;
            xs.push_back(x);
            xs.push_back(x2);
            events.push_back({y,  x,  x2, +1});
            events.push_back({y2, x,  x2, -1});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        int segN = max(0, (int)xs.size() - 1);
        SegTree st(segN, &xs);

        struct Slab { long long y1, y2; long double L; };
        vector<Slab> slabs;
        slabs.reserve(events.size());

        auto xid = [&](long long x) {
            return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        };

        long double total = 0.0L;
        long double covered = 0.0L;

        long long prevY = events[0].y;
        int m = (int)events.size();
        int i = 0;

        while (i < m) {
            long long y = events[i].y;
            long long dy = y - prevY;
            if (dy > 0) {
                slabs.push_back({prevY, y, covered});
                total += covered * (long double)dy;
            }

            // apply all events at y
            while (i < m && events[i].y == y) {
                int l = xid(events[i].x1);
                int r = xid(events[i].x2);
                st.update(l, r, events[i].type);
                i++;
            }

            covered = st.totalLen();
            prevY = y;
        }

        long double half = total / 2.0L;
        long double pref = 0.0L;

        for (auto &sl : slabs) {
            long double dy = (long double)(sl.y2 - sl.y1);
            long double area = sl.L * dy;

            if (pref + area >= half) {
                if (sl.L == 0.0L) {
                    // Area doesn't change in this slab; only valid if already at half.
                    return (double)sl.y1;
                }
                long double ans = (long double)sl.y1 + (half - pref) / sl.L;
                return (double)ans;
            }
            pref += area;
        }

        // Fallback (shouldn't happen with positive total area)
        return (double)prevY;
    }
};
