// @leetcode id=149 questionId=149 slug=max-points-on-a-line lang=cpp site=leetcode.com title="Max Points on a Line"
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 2;
        
        for (int i = 0; i < n; i++) {
            map<pair<int,int>, int> slopeCount;
            int same = 1;
            int localMax = 0;
            
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    same++;
                    continue;
                }
                
                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                
                // Normalize sign: dx positive, or if dx==0 then dy positive
                if (dx < 0) { dx = -dx; dy = -dy; }
                else if (dx == 0 && dy < 0) { dy = -dy; }
                
                slopeCount[{dx, dy}]++;
                localMax = max(localMax, slopeCount[{dx, dy}]);
            }
            
            ans = max(ans, localMax + same);
        }
        
        return ans;
    }
};
