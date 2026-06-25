// @leetcode id=2748 questionId=2831 slug=number-of-beautiful-pairs lang=cpp site=leetcode.com title="Number of Beautiful Pairs"
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // First digit of nums[i]
                int a = nums[i];
                while (a >= 10) a /= 10;
                // Last digit of nums[j]
                int b = nums[j] % 10;
                if (__gcd(a, b) == 1) count++;
            }
        }
        return count;
    }
};
