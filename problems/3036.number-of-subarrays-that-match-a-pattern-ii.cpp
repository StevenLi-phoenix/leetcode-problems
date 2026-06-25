// @leetcode id=3036 questionId=3290 slug=number-of-subarrays-that-match-a-pattern-ii lang=cpp site=leetcode.com title="Number of Subarrays That Match a Pattern II"
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        
        // Convert nums to difference pattern: -1, 0, or 1
        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) diff[i] = 1;
            else if (nums[i + 1] == nums[i]) diff[i] = 0;
            else diff[i] = -1;
        }
        
        // KMP: find occurrences of pattern in diff
        // Build failure function for pattern
        vector<int> fail(m, 0);
        int k = 0;
        for (int i = 1; i < m; i++) {
            while (k > 0 && pattern[k] != pattern[i]) k = fail[k - 1];
            if (pattern[k] == pattern[i]) k++;
            fail[i] = k;
        }
        
        // KMP search
        int count = 0;
        k = 0;
        int len = diff.size(); // n - 1
        for (int i = 0; i < len; i++) {
            while (k > 0 && pattern[k] != diff[i]) k = fail[k - 1];
            if (pattern[k] == diff[i]) k++;
            if (k == m) {
                count++;
                k = fail[k - 1];
            }
        }
        
        return count;
    }
};
