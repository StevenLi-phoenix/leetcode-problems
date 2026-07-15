// @leetcode id=3698 questionId=4015 slug=split-array-with-minimum-difference lang=cpp site=leetcode.com title="Split Array With Minimum Difference"
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> incLen(n), decLen(n);
        incLen[0] = 1;
        for (int i = 1; i < n; i++) {
            incLen[i] = (nums[i] > nums[i - 1]) ? incLen[i - 1] + 1 : 1;
        }
        decLen[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            decLen[i] = (nums[i] > nums[i + 1]) ? decLen[i + 1] + 1 : 1;
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        long long total = prefix[n];

        long long best = -1;
        for (int i = 0; i + 1 < n; i++) {
            if (incLen[i] == i + 1 && decLen[i + 1] == n - i - 1) {
                long long leftSum = prefix[i + 1];
                long long diff = llabs(2 * leftSum - total);
                if (best == -1 || diff < best) best = diff;
            }
        }
        return best;
    }
};
