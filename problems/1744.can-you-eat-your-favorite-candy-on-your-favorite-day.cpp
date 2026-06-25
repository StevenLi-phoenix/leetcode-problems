// @leetcode id=1744 questionId=1872 slug=can-you-eat-your-favorite-candy-on-your-favorite-day lang=cpp site=leetcode.com title="Can You Eat Your Favorite Candy on Your Favorite Day?"
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + candiesCount[i];
        }
        
        vector<bool> result;
        for (auto& q : queries) {
            long long fType = q[0], fDay = q[1], cap = q[2];
            // Min candies eaten by day fDay (eating 1 per day): fDay + 1
            // Max candies eaten by day fDay (eating cap per day): (fDay + 1) * cap
            // Need: min <= total candies in [0..fType] AND max > total candies in [0..fType-1]
            long long minEat = fDay + 1;
            long long maxEat = (fDay + 1) * cap;
            long long totalBefore = prefix[fType];
            long long totalUpTo = prefix[fType + 1];
            // Can eat fType on fDay if:
            // maxEat > totalBefore (can reach fType) AND
            // minEat <= totalUpTo (haven't passed all fType candies)
            result.push_back(maxEat > totalBefore && minEat <= totalUpTo);
        }
        return result;
    }
};
