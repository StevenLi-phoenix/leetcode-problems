// @leetcode id=1024 questionId=1081 slug=video-stitching lang=cpp site=leetcode.com title="Video Stitching"
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> farthest(time, 0); // farthest[s]: max end among clips starting at s
        for (auto& c : clips) {
            if (c[0] < time) {
                farthest[c[0]] = max(farthest[c[0]], c[1]);
            }
        }

        int count = 0, curEnd = 0, nextEnd = 0;
        for (int i = 0; i < time; ++i) {
            nextEnd = max(nextEnd, farthest[i]);
            if (i == curEnd) {
                if (nextEnd <= i) return -1; // cannot extend past i
                ++count;
                curEnd = nextEnd;
                if (curEnd >= time) break;
            }
        }
        return curEnd >= time ? count : -1;
    }
};
