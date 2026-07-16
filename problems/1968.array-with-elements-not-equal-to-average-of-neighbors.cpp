// @leetcode id=1968 questionId=2085 slug=array-with-elements-not-equal-to-average-of-neighbors lang=cpp site=leetcode.com title="Array With Elements Not Equal to Average of Neighbors"
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> result(n);
        int i = 0, j = n - 1;
        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) {
                result[k] = nums[i++];
            } else {
                result[k] = nums[j--];
            }
        }
        return result;
    }
};
