// @leetcode id=1833 questionId=1961 slug=maximum-ice-cream-bars lang=cpp site=leetcode.com title="Maximum Ice Cream Bars"
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Counting sort: costs[i] in [1, 100000]
        const int MAXVAL = 100001;
        vector<int> freq(MAXVAL, 0);
        for (int c : costs) freq[c]++;
        
        int count = 0;
        for (int price = 1; price < MAXVAL && coins > 0; price++) {
            if (freq[price] == 0) continue;
            // Buy as many bars at this price as possible
            int canBuy = min(freq[price], coins / price);
            count += canBuy;
            coins -= canBuy * price;
        }
        return count;
    }
};
