// @leetcode id=3780 questionId=4160 slug=maximum-sum-of-three-numbers-divisible-by-three lang=cpp site=leetcode.com title="Maximum Sum of Three Numbers Divisible by Three"
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> g0, g1, g2;
        for (int x : nums) {
            if (x % 3 == 0) g0.push_back(x);
            else if (x % 3 == 1) g1.push_back(x);
            else g2.push_back(x);
        }
        sort(g0.rbegin(), g0.rend());
        sort(g1.rbegin(), g1.rend());
        sort(g2.rbegin(), g2.rend());
        
        int ans = 0;
        // (0,0,0)
        if (g0.size() >= 3) ans = max(ans, g0[0]+g0[1]+g0[2]);
        // (1,1,1)
        if (g1.size() >= 3) ans = max(ans, g1[0]+g1[1]+g1[2]);
        // (2,2,2)
        if (g2.size() >= 3) ans = max(ans, g2[0]+g2[1]+g2[2]);
        // (0,1,2)
        if (g0.size() >= 1 && g1.size() >= 1 && g2.size() >= 1) 
            ans = max(ans, g0[0]+g1[0]+g2[0]);
        
        return ans;
    }
};
