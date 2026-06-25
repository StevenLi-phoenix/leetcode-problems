// @leetcode id=3411 questionId=3702 slug=maximum-subarray-with-equal-products lang=cpp site=leetcode.com title="Maximum Subarray With Equal Products"
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;

        auto gcd = [](long long a, long long b) {
            while (b) {
                long long t = b;
                b = a % b;
                a = t;
            }
            return a;
        };

        auto lcm = [&](long long a, long long b) {
            return a / gcd(a, b) * b;
        };

        for (int i = 0; i < n; i++) {
            long long prod = 1, g = nums[i], l = nums[i];

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == g * l) {
                    maxLen = max(maxLen, j - i + 1);
                }

                if (prod > 1e15) break;
            }
        }

        return maxLen;
    }
};
