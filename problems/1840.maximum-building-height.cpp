// @leetcode id=1840 questionId=1968 slug=maximum-building-height lang=cpp site=leetcode.com title="Maximum Building Height"
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add building 1 with height 0
        restrictions.push_back({1, 0});
        // Sort by building id
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Forward pass: limit heights based on previous restrictions
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(restrictions[i][1], 
                restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }
        
        // Backward pass: limit heights based on next restrictions
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], 
                restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        
        // Find maximum possible height
        long long ans = n - 1; // unrestricted last building
        // But we need to check between pairs
        ans = restrictions.back()[1] + (n - restrictions.back()[0]);
        
        for (int i = 0; i + 1 < m; i++) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
            // Max height between id1 and id2
            long long maxH = (h1 + h2 + (id2 - id1)) / 2;
            ans = max(ans, maxH);
        }
        
        return (int)ans;
    }
};
