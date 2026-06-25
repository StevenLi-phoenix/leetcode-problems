// @leetcode id=2739 questionId=2857 slug=total-distance-traveled lang=cpp site=leetcode.com title="Total Distance Traveled"
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int totalDistance = 0;
        
        while (mainTank >= 5) {
            mainTank -= 5;
            totalDistance += 50;
            
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        
        totalDistance += mainTank * 10;
        return totalDistance;
    }
};
