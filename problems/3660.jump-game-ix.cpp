// @leetcode id=3660 questionId=3981 slug=jump-game-ix lang=cpp site=leetcode.com title="Jump Game IX"
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        // Compute prefix max and suffix min
        vector<int> prefMax(n), sufMin(n);
        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i-1], nums[i]);
        }
        sufMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            sufMin[i] = min(sufMin[i+1], nums[i]);
        }
        
        // Find segments: a cut exists between i and i+1 when prefMax[i] <= sufMin[i+1]
        // Within each segment, all indices have the same answer = max of segment
        int segStart = 0;
        int segMax = nums[0];
        
        for (int i = 0; i < n; i++) {
            segMax = max(segMax, nums[i]);
            // Check if there's a cut after position i (or if it's the last element)
            bool isCut = (i == n-1) || (prefMax[i] <= sufMin[i+1]);
            if (isCut) {
                // Fill in answers for this segment
                for (int j = segStart; j <= i; j++) {
                    ans[j] = segMax;
                }
                segStart = i + 1;
                if (i + 1 < n) {
                    segMax = nums[i+1];
                }
            }
        }
        
        return ans;
    }
};
