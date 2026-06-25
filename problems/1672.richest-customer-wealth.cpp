// @leetcode id=1672 questionId=1791 slug=richest-customer-wealth lang=cpp site=leetcode.com title="Richest Customer Wealth"
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (const auto& account : accounts) {
            int wealth = 0;
            for (int amount : account) {
                wealth += amount;
            }
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};
