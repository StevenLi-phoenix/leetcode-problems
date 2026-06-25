// @leetcode id=3637 questionId=3952 slug=trionic-array-i lang=cpp site=leetcode.com title="Trionic Array I"
class Solution {
    public:
    bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    if (n < 4) return false;
    int i = 0;
    while (i < n-1 && nums[i] < nums[i+1]) i++;
    if (i == 0 || i >= n-1) return false;
    while (i < n-1 && nums[i] > nums[i+1]) i++;
    if (i >= n-1) return false;
    while (i < n-1 && nums[i] < nums[i+1]) i++;
    return i == n-1;
    }
    };
