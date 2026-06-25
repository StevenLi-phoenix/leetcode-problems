// @leetcode id=2033 questionId=2160 slug=minimum-operations-to-make-a-uni-value-grid lang=cpp site=leetcode.com title="Minimum Operations to Make a Uni-Value Grid"
class Solution {
    public:
    int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> nums;
    for (auto& row : grid)
    for (int val : row)
    nums.push_back(val);
    int rem = nums[0] % x;
    for (int v : nums)
    if (v % x != rem) return -1;
    sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];
    long long ops = 0;
    for (int v : nums)
    ops += abs(v - median) / x;
    return (int)ops;
    }
    };
