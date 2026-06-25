// @leetcode id=3464 questionId=3781 slug=maximize-the-distance-between-points-on-a-square lang=cpp site=leetcode.com title="Maximize the Distance Between Points on a Square"
class Solution {
    public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
    int n = points.size();
    vector<long long> pos(n);
    for (int i = 0; i < n; i++) {
    int x = points[i][0], y = points[i][1];
    if (y == 0) pos[i] = x;
    else if (x == side) pos[i] = (long long)side + y;
    else if (y == side) pos[i] = (long long)2LL*side + (side - x);
    else pos[i] = (long long)3LL*side + (side - y);
    }
    sort(pos.begin(), pos.end());
    long long perimeter = 4LL * side;
    vector<long long> pos2(2*n);
    for (int i = 0; i < n; i++) pos2[i] = pos[i];
    for (int i = 0; i < n; i++) pos2[i+n] = pos[i] + perimeter;
    auto check = [&](long long d) -> bool {
    for (int start = 0; start < n; start++) {
    long long limit = pos[start] + perimeter - d;
    long long cur = pos[start];
    int cnt = 1;
    for (int j = 1; j < k; j++) {
    auto it = lower_bound(pos2.begin() + start + 1, pos2.begin() + start + n, cur + d);
    if (it == pos2.begin() + start + n) break;
    cur = *it;
    if (cur > limit) break;
    cnt++;
    }
    if (cnt >= k) return true;
    }
    return false;
    };
    long long lo = 1, hi = 2LL * side, ans = 0;
    while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (check(mid)) {
    ans = mid;
    lo = mid + 1;
    } else {
    hi = mid - 1;
    }
    }
    return (int)ans;
    }
    };
