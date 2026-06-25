// @leetcode id=335 questionId=335 slug=self-crossing lang=cpp site=leetcode.com title="Self Crossing"
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if (n < 4) return false;
        
        for (int i = 3; i < n; i++) {
            // Check if i-th line crosses with (i-3)-th line
            if (i == 3) {
                // 4th line crosses 1st line
                if (distance[i] >= distance[i-2] && 
                    distance[i-1] <= distance[i-3]) {
                    return true;
                }
            }
            // Check if i-th line crosses with (i-4)-th line
            else if (i == 4) {
                // 5th line crosses 1st line
                if (distance[i-1] == distance[i-3] &&
                    distance[i] + distance[i-4] >= distance[i-2]) {
                    return true;
                }
            }
            // Check for all other cases
            else {
                // Current line crosses with (i-3)-th line
                if (distance[i] >= distance[i-2] &&
                    distance[i-1] <= distance[i-3]) {
                    return true;
                }
                // Current line crosses with (i-4)-th line
                if (distance[i-1] == distance[i-3] &&
                    distance[i] + distance[i-4] >= distance[i-2]) {
                    return true;
                }
                // Current line crosses with (i-5)-th line
                if (distance[i-2] > distance[i-4] &&
                    distance[i-3] >= distance[i-1] &&
                    distance[i-1] + distance[i-5] >= distance[i-3] &&
                    distance[i] + distance[i-4] >= distance[i-2]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
