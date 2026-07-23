// @leetcode id=2670 questionId=2777 slug=find-the-distinct-difference-array lang=cpp site=leetcode.com title="Find the Distinct Difference Array"
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            unordered_set<int> prefix(nums.begin(), nums.begin() + i + 1);
            unordered_set<int> suffix(nums.begin() + i + 1, nums.end());
            diff[i] = (int)prefix.size() - (int)suffix.size();
        }
        return diff;
    }
};
