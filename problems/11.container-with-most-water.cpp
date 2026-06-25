// @leetcode id=11 questionId=11 slug=container-with-most-water lang=cpp site=leetcode.com title="Container With Most Water"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        int l = 0, r = n - 1;
        long long best = 0;

        while (l < r) {
            long long h = min(height[l], height[r]);
            long long w = r - l;
            best = max(best, h * w);

            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return (int)best;
    }
};
