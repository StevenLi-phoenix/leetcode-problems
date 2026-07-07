// @leetcode id=2261 questionId=2339 slug=k-divisible-elements-subarrays lang=cpp site=leetcode.com title="K Divisible Elements Subarrays"
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> seen;

        for (int i = 0; i < n; ++i) {
            vector<int> sub;
            int divisible = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] % p == 0) ++divisible;
                if (divisible > k) break;
                sub.push_back(nums[j]);
                seen.insert(sub);
            }
        }
        return seen.size();
    }
};
