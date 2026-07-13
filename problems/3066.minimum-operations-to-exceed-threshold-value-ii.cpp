// @leetcode id=3066 questionId=3332 slug=minimum-operations-to-exceed-threshold-value-ii lang=cpp site=leetcode.com title="Minimum Operations to Exceed Threshold Value II"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ops = 0;
        while (pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            ops++;
        }
        return ops;
    }
};
