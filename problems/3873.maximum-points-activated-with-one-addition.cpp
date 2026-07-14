// @leetcode id=3873 questionId=4249 slug=maximum-points-activated-with-one-addition lang=cpp site=leetcode.com title="Maximum Points Activated with One Addition"
class Solution {
public:
    vector<int> parent_, size_;

    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size_[a] < size_[b]) swap(a, b);
        parent_[b] = a;
        size_[a] += size_[b];
    }

    int maxActivated(vector<vector<int>>& points) {
        unordered_map<long long, int> xId, yId;
        int nextId = 0;
        for (auto& p : points) {
            if (!xId.count(p[0])) xId[p[0]] = nextId++;
            if (!yId.count(p[1])) yId[p[1]] = nextId++;
        }

        parent_.resize(nextId);
        size_.assign(nextId, 0);
        for (int i = 0; i < nextId; i++) parent_[i] = i;

        for (auto& p : points) {
            int xn = xId[p[0]], yn = yId[p[1]];
            unite(xn, yn);
        }
        // Tally point counts per component root (size_ tracks node count,
        // not point count, so recompute directly from the points).
        vector<int> pointCount(nextId, 0);
        for (auto& p : points) {
            int root = find(xId[p[0]]);
            pointCount[root]++;
        }

        int top1 = 0, top2 = 0;
        for (int i = 0; i < nextId; i++) {
            if (find(i) != i) continue; // only roots
            int c = pointCount[i];
            if (c > top1) { top2 = top1; top1 = c; }
            else if (c > top2) top2 = c;
        }

        return top1 + top2 + 1;
    }
};
