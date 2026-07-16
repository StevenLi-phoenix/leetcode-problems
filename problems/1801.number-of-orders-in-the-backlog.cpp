// @leetcode id=1801 questionId=1928 slug=number-of-orders-in-the-backlog lang=cpp site=leetcode.com title="Number of Orders in the Backlog"
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<long long, long long>> buyHeap; // max-heap by price
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> sellHeap; // min-heap by price

        for (auto& o : orders) {
            long long price = o[0], amount = o[1];
            int type = o[2];

            if (type == 0) {
                while (amount > 0 && !sellHeap.empty() && sellHeap.top().first <= price) {
                    auto [sp, sa] = sellHeap.top(); sellHeap.pop();
                    long long matched = min(amount, sa);
                    amount -= matched;
                    sa -= matched;
                    if (sa > 0) sellHeap.push({sp, sa});
                }
                if (amount > 0) buyHeap.push({price, amount});
            } else {
                while (amount > 0 && !buyHeap.empty() && buyHeap.top().first >= price) {
                    auto [bp, ba] = buyHeap.top(); buyHeap.pop();
                    long long matched = min(amount, ba);
                    amount -= matched;
                    ba -= matched;
                    if (ba > 0) buyHeap.push({bp, ba});
                }
                if (amount > 0) sellHeap.push({price, amount});
            }
        }

        const long long MOD = 1e9 + 7;
        long long total = 0;
        while (!buyHeap.empty()) { total = (total + buyHeap.top().second) % MOD; buyHeap.pop(); }
        while (!sellHeap.empty()) { total = (total + sellHeap.top().second) % MOD; sellHeap.pop(); }
        return (int)total;
    }
};
