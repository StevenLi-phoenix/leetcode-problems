// @leetcode id=1109 questionId=1206 slug=corporate-flight-bookings lang=cpp site=leetcode.com title="Corporate Flight Bookings"
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        for (auto& b : bookings) {
            diff[b[0] - 1] += b[2];
            diff[b[1]] -= b[2];
        }
        vector<int> ans(n);
        int running = 0;
        for (int i = 0; i < n; i++) {
            running += diff[i];
            ans[i] = running;
        }
        return ans;
    }
};
