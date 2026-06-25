// @leetcode id=1094 questionId=1184 slug=car-pooling lang=cpp site=leetcode.com title="Car Pooling"
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Use difference array approach
        // locations are at most 1000
        vector<int> diff(1001, 0);
        for (auto& trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            diff[from] += num;
            diff[to] -= num;
        }
        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if (curr > capacity) return false;
        }
        return true;
    }
};
