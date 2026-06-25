// @leetcode id=3721 questionId=4047 slug=longest-balanced-subarray-ii lang=cpp site=leetcode.com title="Longest Balanced Subarray II"
class Solution {
public:
int longestBalanced(vector<int>& nums) {
int n = nums.size();
if (n == 0) return 0;

// For each value, store all occurrence positions
unordered_map<int, queue<int>> pos;
for (int i = 0; i < n; i++) {
pos[nums[i]].push(i);
}

// Build initial difference array and prefix sums
// For left boundary = 0, first occurrence of each value contributes
// +1 for even, -1 for odd
vector<int> prefSum(n);
unordered_map<int, int> firstOcc; // value -> first occurrence index
vector<int> diff(n, 0);
for (int i = 0; i < n; i++) {
if (firstOcc.find(nums[i]) == firstOcc.end()) {
firstOcc[nums[i]] = i;
diff[i] = (nums[i] % 2 == 0) ? 1 : -1;
}
}
prefSum[0] = diff[0];
for (int i = 1; i < n; i++) {
prefSum[i] = prefSum[i-1] + diff[i];
}

// Segment tree with lazy propagation
// Each node stores min, max values and lazy add
int sz = 4 * n;
vector<int> mn(sz), mx(sz), lazy(sz, 0);

function<void(int, int, int)> build = [&](int node, int lo, int hi) {
lazy[node] = 0;
if (lo == hi) {
mn[node] = mx[node] = prefSum[lo];
return;
}
int mid = (lo + hi) / 2;
build(2*node, lo, mid);
build(2*node+1, mid+1, hi);
mn[node] = min(mn[2*node], mn[2*node+1]);
mx[node] = max(mx[2*node], mx[2*node+1]);
};

function<void(int, int)> pushDown = [&](int node, int val) {
mn[node] += val;
mx[node] += val;
lazy[node] += val;
};

function<void(int)> push = [&](int node) {
if (lazy[node] != 0) {
pushDown(2*node, lazy[node]);
pushDown(2*node+1, lazy[node]);
lazy[node] = 0;
}
};

function<void(int, int, int, int, int, int)> update = [&](int node, int lo, int hi, int l, int r, int val) {
if (r < lo || hi < l) return;
if (l <= lo && hi <= r) {
pushDown(node, val);
return;
}
push(node);
int mid = (lo + hi) / 2;
update(2*node, lo, mid, l, r, val);
update(2*node+1, mid+1, hi, l, r, val);
mn[node] = min(mn[2*node], mn[2*node+1]);
mx[node] = max(mx[2*node], mx[2*node+1]);
};

// Query: find rightmost index in [ql, qr] with value == target
// Using discrete IVT: if min <= target <= max, then target exists
function<int(int, int, int, int, int, int)> queryRightmost = [&](int node, int lo, int hi, int ql, int qr, int target) -> int {
if (qr < lo || hi < ql) return -1;
if (mn[node] > target || mx[node] < target) return -1;
if (lo == hi) return lo;
push(node);
int mid = (lo + hi) / 2;
// Check right child first for rightmost
int res = queryRightmost(2*node+1, mid+1, hi, ql, qr, target);
if (res != -1) return res;
return queryRightmost(2*node, lo, mid, ql, qr, target);
};

build(1, 0, n-1);

int ans = 0;

// Re-build position queues
unordered_map<int, queue<int>> posQ;
for (int i = 0; i < n; i++) {
posQ[nums[i]].push(i);
}

// Iterate over left boundaries
for (int l = 0; l < n; l++) {
// Query for rightmost r >= l where balance(l, r) = 0
// balance(l, r) = prefSum[r] in the segment tree
// We want prefSum[r] = 0
int r = queryRightmost(1, 0, n-1, l, n-1, 0);
if (r != -1) {
ans = max(ans, r - l + 1);
}

// Move left boundary: remove nums[l]
int v = nums[l];
int sign = (v % 2 == 0) ? 1 : -1; // contribution of this value
posQ[v].pop();
int nxt = posQ[v].empty() ? n : posQ[v].front();

// Remove the contribution of v for positions [l, nxt-1]
// balance decreases by sign for r in [l, nxt-1]
if (l <= nxt - 1) {
update(1, 0, n-1, l, nxt - 1, -sign);
}
}

return ans;
}
};
