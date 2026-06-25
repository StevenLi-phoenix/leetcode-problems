// @leetcode id=228 questionId=228 slug=summary-ranges lang=cpp site=leetcode.com title="Summary Ranges"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        for (int i = 0; i < n; ) {
            int start = i;
            while (i + 1 < n && nums[i+1] == nums[i] + 1) i++;
            if (i == start) result.push_back(to_string(nums[start]));
            else result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            i++;
        }
        return result;
    }
};
