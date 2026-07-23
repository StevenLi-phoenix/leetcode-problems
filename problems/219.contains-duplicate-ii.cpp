// @leetcode id=219 questionId=219 slug=contains-duplicate-ii lang=cpp site=leetcode.com title="Contains Duplicate II"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIdx;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = lastIdx.find(nums[i]);
            if (it != lastIdx.end() && i - it->second <= k) return true;
            lastIdx[nums[i]] = i;
        }
        return false;
    }
};
