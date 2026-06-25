// @leetcode id=3386 questionId=3632 slug=button-with-longest-push-time lang=cpp site=leetcode.com title="Button with Longest Push Time"
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = events[0][0];
        int maxTime = events[0][1];
        
        for (int i = 1; i < events.size(); i++) {
            int duration = events[i][1] - events[i-1][1];
            if (duration > maxTime || (duration == maxTime && events[i][0] < ans)) {
                maxTime = duration;
                ans = events[i][0];
            }
        }
        return ans;
    }
};
