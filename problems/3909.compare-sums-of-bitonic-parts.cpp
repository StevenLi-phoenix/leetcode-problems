// @leetcode id=3909 questionId=4292 slug=compare-sums-of-bitonic-parts lang=cpp site=leetcode.com title="Compare Sums of Bitonic Parts"
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        // Find peak
        int peak = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[peak]) peak = i;
        }
        
        // Sum ascending part (0 to peak inclusive)
        long long ascSum = 0;
        for (int i = 0; i <= peak; i++) ascSum += nums[i];
        
        // Sum descending part (peak to n-1 inclusive)
        long long descSum = 0;
        for (int i = peak; i < n; i++) descSum += nums[i];
        
        if (ascSum > descSum) return 0;
        if (descSum > ascSum) return 1;
        return -1;
    }
};
