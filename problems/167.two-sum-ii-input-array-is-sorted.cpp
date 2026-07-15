// @leetcode id=167 questionId=167 slug=two-sum-ii-input-array-is-sorted lang=cpp site=leetcode.com title="Two Sum II - Input Array Is Sorted"
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1};
            if (sum < target) left++;
            else right--;
        }
        return {};
    }
};
