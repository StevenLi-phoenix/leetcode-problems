// @leetcode id=835 questionId=864 slug=image-overlap lang=cpp site=leetcode.com title="Image Overlap"
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        unordered_map<int, int> offsetCount;
        int best = 0;
        for (auto& [x1, y1] : ones1) {
            for (auto& [x2, y2] : ones2) {
                int key = (x1 - x2 + n) * 100 + (y1 - y2 + n);
                int c = ++offsetCount[key];
                best = max(best, c);
            }
        }
        return best;
    }
};
