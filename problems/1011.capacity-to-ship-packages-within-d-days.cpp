// @leetcode id=1011 questionId=1056 slug=capacity-to-ship-packages-within-d-days lang=cpp site=leetcode.com title="Capacity To Ship Packages Within D Days"
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (int w : weights) right += w;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1, current = 0;
        for (int w : weights) {
            if (current + w > capacity) {
                daysNeeded++;
                current = 0;
            }
            current += w;
        }
        return daysNeeded <= days;
    }
};
