// @leetcode id=1546 questionId=1649 slug=maximum-number-of-non-overlapping-subarrays-with-sum-equals-target lang=cpp site=leetcode.com title="Maximum Number of Non-Overlapping Subarrays With Sum Equals Target"
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        int prefixSum = 0;
        // Map from prefix sum to latest index
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;
        int lastEnd = -1; // end index of last selected subarray
        
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int need = prefixSum - target;
            if (prefixMap.count(need) && prefixMap[need] >= lastEnd) {
                count++;
                lastEnd = i;
                // Reset prefix map for next search
                prefixMap.clear();
                prefixMap[prefixSum] = i;
            } else {
                prefixMap[prefixSum] = i;
            }
        }
        return count;
    }
};
