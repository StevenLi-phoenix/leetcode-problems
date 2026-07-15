// @leetcode id=3469 questionId=3776 slug=find-minimum-cost-to-remove-array-elements lang=cpp site=leetcode.com title="Find Minimum Cost to Remove Array Elements"
class Solution {
public:
    int minCost(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        memo.clear();
        return (int)solve(0, -1);
    }

private:
    int n;
    vector<int> nums;
    unordered_map<long long, long long> memo;

    long long solve(int i, int carry) {
        long long key = (long long)i * 1000003LL + (carry + 1);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        long long result;
        if (carry == -1) {
            int remaining = n - i;
            if (remaining == 0) {
                result = 0;
            } else if (remaining < 3) {
                int mx = nums[i];
                for (int k = i + 1; k < n; k++) mx = max(mx, nums[k]);
                result = mx;
            } else {
                long long o1 = (long long)max(nums[i + 1], nums[i + 2]) + solve(i + 3, nums[i]);
                long long o2 = (long long)max(nums[i], nums[i + 2]) + solve(i + 3, nums[i + 1]);
                long long o3 = (long long)max(nums[i], nums[i + 1]) + solve(i + 3, nums[i + 2]);
                result = min({o1, o2, o3});
            }
        } else {
            int remaining = n - i; // new elements available, plus the carry
            if (remaining == 0) {
                result = carry;
            } else if (remaining == 1) {
                result = max(carry, nums[i]);
            } else {
                long long o1 = (long long)max(nums[i], nums[i + 1]) + solve(i + 2, carry);
                long long o2 = (long long)max(carry, nums[i + 1]) + solve(i + 2, nums[i]);
                long long o3 = (long long)max(carry, nums[i]) + solve(i + 2, nums[i + 1]);
                result = min({o1, o2, o3});
            }
        }

        memo[key] = result;
        return result;
    }
};
