// @leetcode id=3488 questionId=3750 slug=closest-equal-element-queries lang=cpp site=leetcode.com title="Closest Equal Element Queries"
class Solution {
    public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) pos[nums[i]].push_back(i);
    vector<int> ans;
    for (int q : queries) {
    auto& idx = pos[nums[q]];
    int m = idx.size();
    if (m == 1) { ans.push_back(-1); continue; }
    int p = (int)(lower_bound(idx.begin(), idx.end(), q) - idx.begin());
    int best = INT_MAX;
    int prev = (p - 1 + m) % m;
    int next = (p + 1) % m;
    auto circ = [&](int j) {
    int d = abs(j - q);
    return min(d, n - d);
    };
    best = min(best, circ(idx[prev]));
    best = min(best, circ(idx[next]));
    ans.push_back(best);
    }
    return ans;
    }
    };
