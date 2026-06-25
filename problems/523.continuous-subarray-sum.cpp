// @leetcode id=523 questionId=523 slug=continuous-subarray-sum lang=cpp site=leetcode.com title="Continuous Subarray Sum"
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // prefix_sum % k -> first occurrence index
        unordered_map<int, int> modMap;
        modMap[0] = -1; // empty prefix with remainder 0
        
        int prefixSum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            prefixSum += nums[i];
            int rem = prefixSum % k;
            
            if (modMap.count(rem)) {
                // found same remainder at earlier index
                if (i - modMap[rem] >= 2) {
                    return true;
                }
            } else {
                modMap[rem] = i;
            }
        }
        return false;
    }
};
