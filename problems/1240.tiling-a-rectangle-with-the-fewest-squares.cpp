// @leetcode id=1240 questionId=1361 slug=tiling-a-rectangle-with-the-fewest-squares lang=cpp site=leetcode.com title="Tiling a Rectangle with the Fewest Squares"
class Solution {
public:
    int ans;
    
    void backtrack(vector<int>& heights, int n, int m, int count) {
        if (count >= ans) return;
        
        // Find the column with minimum height (the leftmost one to fill)
        int minH = *min_element(heights.begin(), heights.end());
        if (minH == n) {
            ans = min(ans, count);
            return;
        }
        
        // Find the leftmost column with minimum height
        int left = 0;
        while (heights[left] != minH) left++;
        
        // Find the rightmost consecutive column with the same minimum height
        int right = left;
        while (right + 1 < m && heights[right + 1] == minH) right++;
        
        // Try placing a square of size s, s can go from 1 to min(right-left+1, n-minH)
        int maxSize = min(right - left + 1, n - minH);
        for (int s = maxSize; s >= 1; s--) {
            // Place square from column left to left+s-1, height minH to minH+s
            for (int j = left; j < left + s; j++) {
                heights[j] += s;
            }
            backtrack(heights, n, m, count + 1);
            for (int j = left; j < left + s; j++) {
                heights[j] -= s;
            }
        }
    }
    
    int tilingRectangle(int n, int m) {
        ans = n * m; // worst case: all 1x1 squares
        vector<int> heights(m, 0);
        backtrack(heights, n, m, 0);
        return ans;
    }
};
