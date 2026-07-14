// @leetcode id=218 questionId=218 slug=the-skyline-problem lang=cpp site=leetcode.com title="The Skyline Problem"
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // events: (x, height, isStart); use negative height for starts so
        // sorting puts starts before ends at the same x, and taller starts
        // before shorter ones.
        vector<tuple<int, int, bool>> events;
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2], true});
            events.push_back({b[1], b[2], false});
        }
        sort(events.begin(), events.end());

        multiset<int> heights = {0};
        vector<vector<int>> result;
        int prevMax = 0;

        for (auto& [x, h, isStart] : events) {
            if (isStart) heights.insert(-h);
            else heights.erase(heights.find(h));

            int curMax = *heights.rbegin();
            if (curMax != prevMax) {
                result.push_back({x, curMax});
                prevMax = curMax;
            }
        }
        return result;
    }
};
