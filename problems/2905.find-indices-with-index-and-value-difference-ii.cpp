// @leetcode id=2905 questionId=3170 slug=find-indices-with-index-and-value-difference-ii lang=cpp site=leetcode.com title="Find Indices With Index and Value Difference II"
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int j = indexDifference; j < n; ++j) {
            int i = j - indexDifference;
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;

            if (abs(nums[j] - nums[minIdx]) >= valueDifference) return {minIdx, j};
            if (abs(nums[j] - nums[maxIdx]) >= valueDifference) return {maxIdx, j};
        }
        return {-1, -1};
    }
};
