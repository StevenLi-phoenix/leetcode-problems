// @leetcode id=3901 questionId=4215 slug=good-subsequence-queries lang=cpp site=leetcode.com title="Good Subsequence Queries"
class Solution {
public:
    int n;
    vector<long long> tree;
    vector<long long> b;
    int cntBad;

    void build(int node, int l, int r) {
        if (l == r) { tree[node] = b[l]; return; }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) { tree[node] = b[l]; return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx);
        else update(2 * node + 1, mid + 1, r, idx);
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        n = nums.size();
        b.assign(n, 0);
        cntBad = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % p == 0) b[i] = nums[i] / p;
            else { b[i] = 0; cntBad++; }
        }

        tree.assign(4 * n, 0);
        build(1, 0, n - 1);

        int answer = 0;
        const int SMALL_THRESHOLD = 20;

        for (auto& q : queries) {
            int idx = q[0], val = q[1];
            bool oldBad = (nums[idx] % p != 0);
            nums[idx] = val;
            bool newBad = (nums[idx] % p != 0);
            if (oldBad && !newBad) cntBad--;
            if (!oldBad && newBad) cntBad++;

            b[idx] = newBad ? 0 : (nums[idx] / p);
            update(1, 0, n - 1, idx);

            long long gAll = tree[1];
            bool good = false;

            if (cntBad > 0) {
                good = (gAll == 1);
            } else {
                if (gAll != 1) {
                    good = false;
                } else if (n <= SMALL_THRESHOLD) {
                    vector<long long> prefix(n), suffix(n);
                    prefix[0] = b[0];
                    for (int i = 1; i < n; i++) prefix[i] = gcd(prefix[i - 1], b[i]);
                    suffix[n - 1] = b[n - 1];
                    for (int i = n - 2; i >= 0; i--) suffix[i] = gcd(suffix[i + 1], b[i]);

                    good = false;
                    for (int i = 0; i < n; i++) {
                        long long left = (i == 0) ? 0 : prefix[i - 1];
                        long long right = (i == n - 1) ? 0 : suffix[i + 1];
                        if (gcd(left, right) == 1) { good = true; break; }
                    }
                } else {
                    good = true;
                }
            }

            if (good) answer++;
        }

        return answer;
    }
};
