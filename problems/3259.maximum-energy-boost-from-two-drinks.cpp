// @leetcode id=3259 questionId=3525 slug=maximum-energy-boost-from-two-drinks lang=cpp site=leetcode.com title="Maximum Energy Boost From Two Drinks"
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        // dp[i][0] = max energy if we drink A at hour i
        // dp[i][1] = max energy if we drink B at hour i
        // If same drink: dp[i][0] = dp[i-1][0] + A[i]
        // If switch: dp[i][0] = dp[i-2][1] + A[i] (skip one hour)
        
        vector<long long> dpA(n, 0), dpB(n, 0);
        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];
        
        if (n >= 2) {
            dpA[1] = max((long long)energyDrinkA[1] + dpA[0], (long long)energyDrinkA[1]);
            dpB[1] = max((long long)energyDrinkB[1] + dpB[0], (long long)energyDrinkB[1]);
        }
        
        for (int i = 2; i < n; i++) {
            // Continue with A or switch from B (skipping hour i-1)
            dpA[i] = max(dpA[i-1] + energyDrinkA[i], dpB[i-2] + energyDrinkA[i]);
            // Continue with B or switch from A (skipping hour i-1)
            dpB[i] = max(dpB[i-1] + energyDrinkB[i], dpA[i-2] + energyDrinkB[i]);
        }
        
        return max(dpA[n-1], dpB[n-1]);
    }
};
