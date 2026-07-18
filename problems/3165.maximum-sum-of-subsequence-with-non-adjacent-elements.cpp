// @leetcode id=3165 questionId=3423 slug=maximum-sum-of-subsequence-with-non-adjacent-elements lang=cpp site=leetcode.com title="Maximum Sum of Subsequence With Non-adjacent Elements"
class Solution {
public:
    static const long long MOD = 1000000007;

    struct Node {
        long long d[2][2];
    };

    int n;
    vector<int> arr;
    vector<Node> tree;

    Node makeLeaf(int v) {
        Node node;
        node.d[0][0] = max(0, v);
        node.d[0][1] = 0;
        node.d[1][0] = 0;
        node.d[1][1] = 0;
        return node;
    }

    Node merge(const Node& left, const Node& right) {
        Node res;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                long long opt1 = left.d[a][1] + right.d[0][b];
                long long opt2 = left.d[a][0] + right.d[1][b];
                res.d[a][b] = max(opt1, opt2);
            }
        }
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = makeLeaf(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = makeLeaf(val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(node * 2, l, mid, pos, val);
        else update(node * 2 + 1, mid + 1, r, pos, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        arr = nums;
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        long long ans = 0;
        for (auto& q : queries) {
            int pos = q[0], x = q[1];
            update(1, 0, n - 1, pos, x);
            ans = (ans + tree[1].d[0][0]) % MOD;
        }

        return (int)ans;
    }
};
