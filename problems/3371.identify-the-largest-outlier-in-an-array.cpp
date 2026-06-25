// @leetcode id=3371 questionId=3594 slug=identify-the-largest-outlier-in-an-array lang=cpp site=leetcode.com title="Identify the Largest Outlier in an Array"
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        
        // Frequency map
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        
        int ans = INT_MIN;
        
        for (int x : nums) {
            // Assume x is the outlier
            int rem = total - x;
            if (rem % 2 != 0) continue;
            int needed = rem / 2; // This should be the sum_element
            
            // Check if needed exists in nums (at a different index than x)
            // If needed != x: just check freq[needed] > 0
            // If needed == x: check freq[needed] >= 2 (one for sum_element, one for outlier)
            if (freq.count(needed)) {
                if (needed != x || freq[needed] >= 2) {
                    ans = max(ans, x);
                }
            }
        }
        
        return ans;
    }
};
