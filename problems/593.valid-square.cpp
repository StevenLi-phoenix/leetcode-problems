// @leetcode id=593 questionId=593 slug=valid-square lang=cpp site=leetcode.com title="Valid Square"
class Solution {
public:
    long long dist(vector<int>& p1, vector<int>& p2) {
        long long dx = p1[0] - p2[0];
        long long dy = p1[1] - p2[1];
        return dx*dx + dy*dy;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>*> pts = {&p1, &p2, &p3, &p4};
        
        // Compute all 6 pairwise distances
        vector<long long> dists;
        for (int i = 0; i < 4; i++)
            for (int j = i+1; j < 4; j++)
                dists.push_back(dist(*pts[i], *pts[j]));
        
        sort(dists.begin(), dists.end());
        
        // For a valid square: 4 equal sides (smallest) and 2 equal diagonals (largest)
        // All sides > 0, sides[0-3] equal, diags[4-5] equal, diag = 2*side
        return dists[0] > 0 &&
               dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3] &&
               dists[4] == dists[5] &&
               dists[4] == 2 * dists[0];
    }
};
