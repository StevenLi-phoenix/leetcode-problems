// @leetcode id=624 questionId=624 slug=maximum-distance-in-arrays lang=cpp site=leetcode.com title="Maximum Distance in Arrays"
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int curMin = arrays[0].front();
        int curMax = arrays[0].back();
        int best = 0;

        for (int i = 1; i < (int)arrays.size(); i++) {
            int lo = arrays[i].front();
            int hi = arrays[i].back();

            best = max({best, abs(hi - curMin), abs(curMax - lo)});

            curMin = min(curMin, lo);
            curMax = max(curMax, hi);
        }

        return best;
    }
};
