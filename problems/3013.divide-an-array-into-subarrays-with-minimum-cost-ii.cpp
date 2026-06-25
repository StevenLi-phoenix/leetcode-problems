// @leetcode id=3013 questionId=3260 slug=divide-an-array-into-subarrays-with-minimum-cost-ii lang=cpp site=leetcode.com title="Divide an Array Into Subarrays With Minimum Cost II"
class Solution {
    public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
    int n = nums.size();
    long long ans = LLONG_MAX;
    multiset<int> small, large;
    long long smallSum = 0;
    int need = k - 1;
    auto balance = [&]() {
    while ((int)small.size() > need) {
    auto it = prev(small.end());
    smallSum -= *it;
    large.insert(*it);
    small.erase(it);
    }
    while ((int)small.size() < need && !large.empty()) {
    auto it = large.begin();
    smallSum += *it;
    small.insert(*it);
    large.erase(it);
    }
    };
    auto add = [&](int x) {
    if (small.empty() || x <= *prev(small.end())) {
    small.insert(x);
    smallSum += x;
    } else {
    large.insert(x);
    }
    balance();
    };
    auto rem = [&](int x) {
    auto it = small.find(x);
    if (it != small.end()) {
    smallSum -= *it;
    small.erase(it);
    } else {
    large.erase(large.find(x));
    }
    balance();
    };
    for (int i = 1; i < n && i <= dist + 1; i++) {
    add(nums[i]);
    }
    if ((int)small.size() == need) {
    ans = min(ans, (long long)nums[0] + smallSum);
    }
    for (int i = dist + 2; i < n; i++) {
    rem(nums[i - dist - 1]);
    add(nums[i]);
    if ((int)small.size() == need) {
    ans = min(ans, (long long)nums[0] + smallSum);
    }
    }
    return ans;
    }
    };
