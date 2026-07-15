// @leetcode id=2462 questionId=2553 slug=total-cost-to-hire-k-workers lang=cpp site=leetcode.com title="Total Cost to Hire K Workers"
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;
        int lo = 0, hi = n - 1;

        for (int i = 0; i < candidates && lo <= hi; i++) {
            left.push(costs[lo++]);
        }
        for (int i = 0; i < candidates && lo <= hi; i++) {
            right.push(costs[hi--]);
        }

        long long total = 0;
        for (int i = 0; i < k; i++) {
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                total += left.top();
                left.pop();
                if (lo <= hi) left.push(costs[lo++]);
            } else {
                total += right.top();
                right.pop();
                if (lo <= hi) right.push(costs[hi--]);
            }
        }
        return total;
    }
};
