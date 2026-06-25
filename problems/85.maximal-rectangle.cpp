// @leetcode id=85 questionId=85 slug=maximal-rectangle lang=cpp site=leetcode.com title="Maximal Rectangle"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = (int)matrix.size();
        if (rows == 0) return 0;
        int cols = (int)matrix[0].size();
        if (cols == 0) return 0;

        vector<int> heights(cols, 0);
        int best = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            best = max(best, largestRectangleArea(heights));
        }
        return best;
    }

private:
    int largestRectangleArea(const vector<int>& h) {
        int n = (int)h.size();
        vector<int> st; // stack of indices, heights increasing
        st.reserve(n);
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? 0 : h[i]; // sentinel 0 to flush stack
            while (!st.empty() && h[st.back()] > cur) {
                int height = h[st.back()];
                st.pop_back();
                int leftLessIdx = st.empty() ? -1 : st.back();
                int width = i - leftLessIdx - 1;
                ans = max(ans, height * width);
            }
            st.push_back(i);
        }
        return ans;
    }
};
