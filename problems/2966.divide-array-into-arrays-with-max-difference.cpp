// @leetcode id=2966 questionId=3241 slug=divide-array-into-arrays-with-max-difference lang=cpp site=leetcode.com title="Divide Array Into Arrays With Max Difference"
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) return {};
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return result;
    }
};
