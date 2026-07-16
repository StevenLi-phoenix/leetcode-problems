// @leetcode id=3862 questionId=4240 slug=find-the-smallest-balanced-index lang=cpp site=leetcode.com title="Find the Smallest Balanced Index"
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        const long long CAP = 200000000000000LL; // larger than max possible sum (1e5 * 1e9 = 1e14)

        vector<long long> prefixSum(n);
        prefixSum[0] = 0;
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        vector<long long> suffixProduct(n);
        long long prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            suffixProduct[i] = prod;
            if (prod < CAP) {
                if (nums[i] != 0 && prod > CAP / nums[i]) {
                    prod = CAP;
                } else {
                    prod *= nums[i];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == suffixProduct[i]) return i;
        }
        return -1;
    }
};
