// @leetcode id=473 questionId=473 slug=matchsticks-to-square lang=cpp site=leetcode.com title="Matchsticks to Square"
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int total = 0;
        for (int x : matchsticks) total += x;
        if (total % 4 != 0) return false;
        int side = total / 4;
        
        // Sort descending for better pruning
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if (matchsticks[0] > side) return false;
        
        vector<int> sides(4, 0);
        
        function<bool(int)> dfs = [&](int idx) -> bool {
            if (idx == n) {
                return sides[0] == side && sides[1] == side && sides[2] == side;
            }
            
            set<int> tried;
            for (int i = 0; i < 4; i++) {
                if (tried.count(sides[i])) continue;
                if (sides[i] + matchsticks[idx] > side) continue;
                tried.insert(sides[i]);
                sides[i] += matchsticks[idx];
                if (dfs(idx + 1)) return true;
                sides[i] -= matchsticks[idx];
            }
            return false;
        };
        
        return dfs(0);
    }
};
