// @leetcode id=1675 questionId=1794 slug=minimize-deviation-in-array lang=cpp site=leetcode.com title="Minimize Deviation in Array"
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxHeap; // all values pushed to their max reachable (odd*2)
        long long minVal = LLONG_MAX;

        for (int v : nums) {
            long long x = (v % 2 == 1) ? (long long)v * 2 : v;
            maxHeap.push(x);
            minVal = min(minVal, x);
        }

        long long best = LLONG_MAX;
        while (true) {
            long long top = maxHeap.top();
            maxHeap.pop();
            best = min(best, top - minVal);
            if (top % 2 != 0) break; // can't shrink further
            long long half = top / 2;
            minVal = min(minVal, half);
            maxHeap.push(half);
        }
        return (int)best;
    }
};
