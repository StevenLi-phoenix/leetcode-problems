// @leetcode id=1871 questionId=2001 slug=jump-game-vii lang=cpp site=leetcode.com title="Jump Game VII"
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;
        
        // dp[i] = true if index i is reachable
        vector<bool> dp(n, false);
        dp[0] = true;
        
        // prefix sum to count reachable indices in a window
        int pre = 0;
        
        for (int i = 1; i < n; i++) {
            if (i >= minJump) pre += dp[i - minJump];
            if (i > maxJump) pre -= dp[i - maxJump - 1];
            if (pre > 0 && s[i] == '0') dp[i] = true;
        }
        
        return dp[n - 1];
    }
};
