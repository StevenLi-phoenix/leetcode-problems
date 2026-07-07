// @leetcode id=42 questionId=42 slug=trapping-rain-water lang=cpp site=leetcode.com title="Trapping Rain Water"
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int total = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                total += leftMax - height[left];
                ++left;
            } else {
                rightMax = max(rightMax, height[right]);
                total += rightMax - height[right];
                --right;
            }
        }
        return total;
    }
};
