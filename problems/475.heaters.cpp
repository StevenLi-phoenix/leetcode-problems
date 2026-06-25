// @leetcode id=475 questionId=475 slug=heaters lang=cpp site=leetcode.com title="Heaters"
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        
        for (int house : houses) {
            // Binary search for closest heater
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int minDist = INT_MAX;
            
            if (it != heaters.end()) {
                minDist = min(minDist, (int)(*it - house));
            }
            if (it != heaters.begin()) {
                --it;
                minDist = min(minDist, (int)(house - *it));
            }
            
            ans = max(ans, minDist);
        }
        
        return ans;
    }
};
