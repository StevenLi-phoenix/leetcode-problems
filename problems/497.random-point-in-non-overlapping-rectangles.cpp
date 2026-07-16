// @leetcode id=497 questionId=914 slug=random-point-in-non-overlapping-rectangles lang=cpp site=leetcode.com title="Random Point in Non-overlapping Rectangles"
class Solution {
public:
    vector<vector<int>> rects;
    vector<long long> prefix;

    Solution(vector<vector<int>>& rects_) {
        rects = rects_;
        prefix.resize(rects.size());
        long long total = 0;
        for (int i = 0; i < (int)rects.size(); i++) {
            long long w = (long long)(rects[i][2] - rects[i][0] + 1);
            long long h = (long long)(rects[i][3] - rects[i][1] + 1);
            total += w * h;
            prefix[i] = total;
        }
    }

    vector<int> pick() {
        long long target = (long long)(rand()) * (long long)(RAND_MAX + 1LL) + rand();
        target %= prefix.back();
        int idx = upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
        auto& r = rects[idx];
        int w = r[2] - r[0] + 1;
        int h = r[3] - r[1] + 1;
        int x = r[0] + rand() % w;
        int y = r[1] + rand() % h;
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
