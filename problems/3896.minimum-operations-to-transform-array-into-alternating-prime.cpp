// @leetcode id=3896 questionId=4277 slug=minimum-operations-to-transform-array-into-alternating-prime lang=cpp site=leetcode.com title="Minimum Operations to Transform Array into Alternating Prime"
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        const int MAXN = 400001;
        vector<bool> isPrime(MAXN, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < MAXN; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAXN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        long long ops = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (i % 2 == 0) {
                // Need prime >= x
                while (!isPrime[x]) x++;
                ops += x - nums[i];
            } else {
                // Need non-prime >= x
                // 1 is non-prime, 4,6,8,9,10... are non-prime
                // Find smallest non-prime >= x
                while (isPrime[x]) x++;
                ops += x - nums[i];
            }
        }
        
        return ops;
    }
};
