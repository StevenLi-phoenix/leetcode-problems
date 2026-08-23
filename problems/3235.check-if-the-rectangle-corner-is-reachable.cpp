// @leetcode id=3235 questionId=3478 slug=check-if-the-rectangle-corner-is-reachable lang=cpp site=leetcode.com title="Check if the Rectangle Corner Is Reachable"
class Solution {
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        int n = circles.size();

        auto sq = [](long long v) { return (__int128)v * v; };

        // distance^2 from (px,py) to nearest point on segment (x1,y1)-(x2,y2), axis-aligned
        auto distToSegmentSq = [&](long long px, long long py, long long x1, long long y1, long long x2, long long y2) {
            long long cx = max(min(px, max(x1, x2)), min(x1, x2));
            long long cy = max(min(py, max(y1, y2)), min(y1, y2));
            return sq(px - cx) + sq(py - cy);
        };

        // check if any circle covers a corner
        for (auto& c : circles) {
            long long cx = c[0], cy = c[1], r = c[2];
            if (sq(cx) + sq(cy) <= sq(r)) return false; // covers (0,0)
            if (sq(cx - xCorner) + sq(cy - yCorner) <= sq(r)) return false; // covers (X,Y)
        }

        vector<int> parent(n + 4);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        int L = n, B = n + 1, R = n + 2, T = n + 3;

        for (int i = 0; i < n; ++i) {
            long long cx = circles[i][0], cy = circles[i][1], r = circles[i][2];
            // A circle only meaningfully touches an edge if it actually has area on the
            // rectangle's interior side of that edge's line -- pure tangency from the
            // outside (disk otherwise entirely outside the rectangle) leaves only an
            // isolated boundary point, which a path can route around.
            if (distToSegmentSq(cx, cy, 0, 0, 0, yCorner) <= sq(r) && cx + r > 0) unite(i, L);
            if (distToSegmentSq(cx, cy, 0, 0, xCorner, 0) <= sq(r) && cy + r > 0) unite(i, B);
            if (distToSegmentSq(cx, cy, xCorner, 0, xCorner, yCorner) <= sq(r) && cx - r < xCorner) unite(i, R);
            if (distToSegmentSq(cx, cy, 0, yCorner, xCorner, yCorner) <= sq(r) && cy - r < yCorner) unite(i, T);
            for (int j = i + 1; j < n; ++j) {
                long long dx = circles[i][0] - circles[j][0], dy = circles[i][1] - circles[j][1];
                long long rsum = (long long)circles[i][2] + circles[j][2];
                if (sq(dx) + sq(dy) <= sq(rsum)) unite(i, j);
            }
        }

        int rL = find(L), rB = find(B), rR = find(R), rT = find(T);
        // blocking iff some component's touched-edge-set is NOT a subset of {L,T} and NOT a subset of {B,R}
        // equivalently: (L,B in same component) or (R,T in same component) or (L,R in same component) or (B,T in same component)
        if (rL == rB) return false;
        if (rR == rT) return false;
        if (rL == rR) return false;
        if (rB == rT) return false;

        return true;
    }
};
