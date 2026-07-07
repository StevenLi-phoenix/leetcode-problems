// @leetcode id=3479 questionId=3791 slug=fruits-into-baskets-iii lang=cpp site=leetcode.com title="Fruits Into Baskets III"
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> tree(4 * n, 0);
        build(tree, baskets, 1, 0, n - 1);

        int unplaced = 0;
        for (int f : fruits) {
            int pos = findAndUse(tree, 1, 0, n - 1, f);
            if (pos == -1) ++unplaced;
        }
        return unplaced;
    }

private:
    void build(vector<int>& tree, vector<int>& baskets, int node, int lo, int hi) {
        if (lo == hi) {
            tree[node] = baskets[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(tree, baskets, 2 * node, lo, mid);
        build(tree, baskets, 2 * node + 1, mid + 1, hi);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // finds leftmost position with capacity >= need, marks it used (-1), returns index or -1
    int findAndUse(vector<int>& tree, int node, int lo, int hi, int need) {
        if (tree[node] < need) return -1;
        if (lo == hi) {
            tree[node] = -1;
            return lo;
        }
        int mid = (lo + hi) / 2;
        int pos = findAndUse(tree, 2 * node, lo, mid, need);
        if (pos == -1) pos = findAndUse(tree, 2 * node + 1, mid + 1, hi, need);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        return pos;
    }
};
