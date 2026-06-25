// @leetcode id=2208 questionId=2310 slug=minimum-operations-to-halve-array-sum lang=cpp site=leetcode.com title="Minimum Operations to Halve Array Sum"
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        double total = 0;
        for (int x : nums) total += x;
        double target = total / 2.0;
        double reduced = 0;
        int ops = 0;
        while (reduced < target) {
            double top = pq.top(); pq.pop();
            double half = top / 2.0;
            reduced += half;
            pq.push(half);
            ops++;
        }
        return ops;
    }
};
