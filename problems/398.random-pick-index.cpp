// @leetcode id=398 questionId=398 slug=random-pick-index lang=cpp site=leetcode.com title="Random Pick Index"
class Solution {
private:
    vector<int> nums;
    unordered_map<int, vector<int>> targetToIndices;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        // Build a map from target value to list of indices
        for (int i = 0; i < nums.size(); i++) {
            targetToIndices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        // Get all indices for the target value
        vector<int>& indices = targetToIndices[target];
        
        // Pick a random index from the list
        int randomIdx = rand() % indices.size();
        return indices[randomIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
