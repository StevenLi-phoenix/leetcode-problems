// @leetcode id=3719 questionId=4045 slug=longest-balanced-subarray-i lang=cpp site=leetcode.com title="Longest Balanced Subarray I"
class Solution {
    public:
    int longestBalanced(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
    unordered_set<int> even_set, odd_set;
    for (int j = i; j < n; j++) {
    if (nums[j] % 2 == 0) even_set.insert(nums[j]);
    else odd_set.insert(nums[j]);
    if (even_set.size() == odd_set.size() && !even_set.empty()) {
    ans = max(ans, j - i + 1);
    }
    }
    }
    return ans;
    }
    };
