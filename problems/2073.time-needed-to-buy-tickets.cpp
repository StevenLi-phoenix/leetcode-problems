// @leetcode id=2073 questionId=2195 slug=time-needed-to-buy-tickets lang=cpp site=leetcode.com title="Time Needed to Buy Tickets"
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        for (int i = 0; i < (int)tickets.size(); ++i) {
            if (i <= k) {
                total += min(tickets[i], tickets[k]);
            } else {
                total += min(tickets[i], tickets[k] - 1);
            }
        }
        return total;
    }
};
