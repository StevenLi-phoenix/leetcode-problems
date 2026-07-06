// @leetcode id=2558 questionId=2692 slug=take-gifts-from-the-richest-pile lang=cpp site=leetcode.com title="Take Gifts From the Richest Pile"
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i) {
            long long top = pq.top();
            pq.pop();
            long long r = (long long)sqrtl((long double)top);
            while (r * r > top) --r;
            while ((r + 1) * (r + 1) <= top) ++r;
            pq.push(r);
        }

        long long total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};
