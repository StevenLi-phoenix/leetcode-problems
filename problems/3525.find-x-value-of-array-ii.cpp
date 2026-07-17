// @leetcode id=3525 questionId=3840 slug=find-x-value-of-array-ii lang=cpp site=leetcode.com title="Find X Value of Array II"
class Solution {
public:
    struct Node {
        int M[5][5];
        int P;
    };

    int K;
    vector<Node> tree;
    int n;

    Node makeLeaf(int v) {
        Node node{};
        int vk = v % K;
        node.P = vk;
        for (int r = 0; r < K; r++) {
            for (int x = 0; x < K; x++) node.M[r][x] = 0;
            node.M[r][r] += 1;
            node.M[r][(r * vk) % K] += 1;
        }
        return node;
    }

    Node merge(const Node& left, const Node& right) {
        Node res{};
        res.P = (left.P * right.P) % K;
        for (int r = 0; r < K; r++) {
            int rl = (r * left.P) % K;
            for (int x = 0; x < K; x++) {
                res.M[r][x] = left.M[r][x] + right.M[rl][x] - (x == rl ? 1 : 0);
            }
        }
        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) { tree[node] = makeLeaf(nums[l]); return; }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = makeLeaf(val); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2 * node, l, mid, ql, qr);
        if (ql > mid) return query(2 * node + 1, mid + 1, r, ql, qr);
        Node leftRes = query(2 * node, l, mid, ql, qr);
        Node rightRes = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(leftRes, rightRes);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);
            int cnt = res.M[1 % K][x];
            if (x == 1 % K) cnt -= 1;
            answer.push_back(cnt);
        }

        return answer;
    }
};
