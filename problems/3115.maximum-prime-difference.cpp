// @leetcode id=3115 questionId=3373 slug=maximum-prime-difference lang=cpp site=leetcode.com title="Maximum Prime Difference"
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        auto isPrime = [](int x) {
            if (x < 2) return false;
            for (int i = 2; (long long)i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };

        int first = -1, last = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (isPrime(nums[i])) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return last - first;
    }
};
