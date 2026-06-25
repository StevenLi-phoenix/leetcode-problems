// @leetcode id=3510 questionId=3772 slug=minimum-pair-removal-to-sort-array-ii lang=cpp site=leetcode.com title="Minimum Pair Removal to Sort Array II"
class Solution {
public:
int minimumPairRemoval(vector<int>& nums) {
int n = nums.size();
vector<long long> val(n);
for (int i = 0; i < n; i++) val[i] = nums[i];
// Use ordered set of active indices
set<int> active;
for (int i = 0; i < n; i++) active.insert(i);
// Count inversions
int inv = 0;
for (int i = 0; i+1 < n; i++) if (val[i] > val[i+1]) inv++;
// Priority queue: {sum, left_idx}
// Use set for dedup instead
set<pair<long long,int>> pq;
auto it0 = active.begin();
while (true) {
auto nx = next(it0);
if (nx == active.end()) break;
pq.insert({val[*it0]+val[*nx], *it0});
it0 = nx;
}
int ops = 0;
while (inv > 0) {
auto [s, li] = *pq.begin();
pq.erase(pq.begin());
// Find current position of li in active
auto lit = active.find(li);
if (lit == active.end()) continue;
auto rit = next(lit);
if (rit == active.end()) continue;
int ri = *rit;
if (val[li] + val[ri] != s) {
// Reinsert with correct sum
pq.insert({val[li]+val[ri], li});
continue;
}
long long newval = val[li] + val[ri];
// Remove old pairs involving ri
auto rnext = next(rit);
if (rnext != active.end()) {
pq.erase({val[ri]+val[*rnext], ri});
}
// Remove old pair (li, ri) is already popped
// Update inversions
if (val[li] > val[ri]) inv--;
auto lprev = (lit != active.begin()) ? prev(lit) : active.end();
if (lprev != active.end()) {
if (val[*lprev] > val[li]) inv--;
if (val[*lprev] > newval) inv++;
pq.erase({val[*lprev]+val[li], *lprev});
pq.insert({val[*lprev]+newval, *lprev});
}
if (rnext != active.end()) {
if (val[ri] > val[*rnext]) inv--;
if (newval > val[*rnext]) inv++;
pq.insert({newval+val[*rnext], li});
}
val[li] = newval;
active.erase(rit);
ops++;
}
return ops;
}
};
