// @leetcode id=330 questionId=330 slug=patching-array lang=cpp site=leetcode.com title="Patching Array"
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach = 0;
        int patches = 0;
        int i = 0;
        int m = nums.size();

        while (reach < n) {
            if (i < m && nums[i] <= reach + 1) {
                reach += nums[i];
                i++;
            } else {
                reach += reach + 1;
                patches++;
            }
        }

        return patches;
    }
};
