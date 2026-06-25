// @leetcode id=3047 questionId=3325 slug=find-the-largest-area-of-square-inside-two-rectangles lang=cpp site=leetcode.com title="Find the Largest Area of Square Inside Two Rectangles"
class Solution {
public:
long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
long long maxArea = 0;
int n = bottomLeft.size();
for (int i = 0; i < n; i++) {
for (int j = i+1; j < n; j++) {
int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
int x2 = min(topRight[i][0], topRight[j][0]);
int y2 = min(topRight[i][1], topRight[j][1]);
if (x2 > x1 && y2 > y1) {
long long side = min(x2-x1, y2-y1);
maxArea = max(maxArea, side*side);
}
}
}
return maxArea;
}
};
