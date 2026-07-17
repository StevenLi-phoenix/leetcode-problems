// @leetcode id=1383 questionId=1499 slug=maximum-performance-of-a-team lang=cpp site=leetcode.com title="Maximum Performance of a Team"
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return efficiency[a] > efficiency[b];
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long speedSum = 0;
        long long best = 0;

        for (int idx : order) {
            speedSum += speed[idx];
            minHeap.push(speed[idx]);

            if ((int)minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }

            long long perf = speedSum * efficiency[idx];
            best = max(best, perf);
        }

        return (int)(best % MOD);
    }
};
