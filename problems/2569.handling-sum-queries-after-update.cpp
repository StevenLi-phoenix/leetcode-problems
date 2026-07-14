// @leetcode id=2569 questionId=2703 slug=handling-sum-queries-after-update lang=cpp site=leetcode.com title="Handling Sum Queries After Update"
class Solution {
public:
    int n_;
    vector<int> cnt;
    vector<bool> lazy;

    void build(vector<int>& nums1, int node, int l, int r) {
        if (l == r) { cnt[node] = nums1[l]; return; }
        int mid = (l + r) / 2;
        build(nums1, node * 2, l, mid);
        build(nums1, node * 2 + 1, mid + 1, r);
        cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }

    void apply(int node, int l, int r) {
        cnt[node] = (r - l + 1) - cnt[node];
        lazy[node] = !lazy[node];
    }

    void push(int node, int l, int r) {
        if (!lazy[node]) return;
        int mid = (l + r) / 2;
        apply(node * 2, l, mid);
        apply(node * 2 + 1, mid + 1, r);
        lazy[node] = false;
    }

    void flip(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(node, l, r); return; }
        push(node, l, r);
        int mid = (l + r) / 2;
        flip(node * 2, l, mid, ql, qr);
        flip(node * 2 + 1, mid + 1, r, ql, qr);
        cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        n_ = nums1.size();
        cnt.assign(4 * n_, 0);
        lazy.assign(4 * n_, false);
        build(nums1, 1, 0, n_ - 1);

        long long sum2 = 0;
        for (int v : nums2) sum2 += v;

        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                flip(1, 0, n_ - 1, q[1], q[2]);
            } else if (q[0] == 2) {
                sum2 += (long long)q[1] * cnt[1];
            } else {
                ans.push_back(sum2);
            }
        }
        return ans;
    }
};
