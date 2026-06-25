// @leetcode id=3684 questionId=3997 slug=maximize-sum-of-at-most-k-distinct-elements lang=cpp site=leetcode.com title="Maximize Sum of At Most K Distinct Elements"
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int, greater<int>> uniqueNums(nums.begin(), nums.end());

        vector<int> result;
        int count = 0;
        for (int num : uniqueNums) {
            if (count >= k) break;
            result.push_back(num);
            count++;
        }

        return result;
    }
};
