// @leetcode id=454 questionId=454 slug=4sum-ii lang=cpp site=leetcode.com title="4Sum II"
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumMap;
        int n = nums1.size();
        
        // Store all sums of nums1[i] + nums2[j]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumMap[nums1[i] + nums2[j]]++;
            }
        }
        
        int count = 0;
        // Find pairs from nums3 + nums4 that negate the sums
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int target = -(nums3[k] + nums4[l]);
                if (sumMap.count(target)) {
                    count += sumMap[target];
                }
            }
        }
        
        return count;
    }
};
