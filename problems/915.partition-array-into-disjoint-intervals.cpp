// @leetcode id=915 questionId=951 slug=partition-array-into-disjoint-intervals lang=cpp site=leetcode.com title="Partition Array into Disjoint Intervals"
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftMax = nums[0];
        int currentMax = nums[0];
        int partitionIdx = 0;

        for (int i = 1; i < n; i++) {
            currentMax = max(currentMax, nums[i]);
            if (nums[i] < leftMax) {
                leftMax = currentMax;
                partitionIdx = i;
            }
        }
        return partitionIdx + 1;
    }
};
