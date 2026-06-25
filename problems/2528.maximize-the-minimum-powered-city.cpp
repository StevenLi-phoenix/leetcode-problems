// @leetcode id=2528 questionId=2618 slug=maximize-the-minimum-powered-city lang=cpp site=leetcode.com title="Maximize the Minimum Powered City"
class Solution {
    public:
    long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    // compute initial power for each city using prefix sum
    vector<long long> psum(n + 1, 0);
    for (int i = 0; i < n; i++) psum[i + 1] = psum[i] + stations[i];
    auto getPower = [&](int i) -> long long {
    int l = max(0, i - r), ri = min(n - 1, i + r);
    return psum[ri + 1] - psum[l];
    };
    vector<long long> power(n);
    for (int i = 0; i < n; i++) power[i] = getPower(i);
    auto check = [&](long long target) -> bool {
    vector<long long> add(n, 0);
    long long extra = 0, used = 0;
    for (int i = 0; i < n; i++) {
    extra += add[i];
    long long cur = power[i] + extra;
    if (cur < target) {
    long long need = target - cur;
    used += need;
    if (used > k) return false;
    extra += need;
    int rr = min(n - 1, i + 2 * r);
    if (rr + 1 < n) add[rr + 1] -= need;
    }
    }
    return true;
    };
    long long lo = 0, hi = 2e15, ans = 0;
    while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    if (check(mid)) { ans = mid; lo = mid + 1; }
    else hi = mid - 1;
    }
    return ans;
    }
    };
