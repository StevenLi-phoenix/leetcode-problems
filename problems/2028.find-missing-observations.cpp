// @leetcode id=2028 questionId=2155 slug=find-missing-observations lang=cpp site=leetcode.com title="Find Missing Observations"
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = (n + m) * mean;
        int currentSum = 0;
        for (int r : rolls) currentSum += r;
        int missingSum = totalSum - currentSum;
        
        // Check feasibility
        if (missingSum < n || missingSum > 6 * n) return {};
        
        int base = missingSum / n;
        int remainder = missingSum % n;
        
        vector<int> result(n, base);
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }
        
        return result;
    }
};
