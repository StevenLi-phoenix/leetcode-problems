// @leetcode id=1561 questionId=1683 slug=maximum-number-of-coins-you-can-get lang=cpp site=leetcode.com title="Maximum Number of Coins You Can Get"
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int total = 0;
        int rounds = n / 3;
        int j = n - 2;
        for (int i = 0; i < rounds; i++) {
            total += piles[j];
            j -= 2;
        }
        return total;
    }
};
