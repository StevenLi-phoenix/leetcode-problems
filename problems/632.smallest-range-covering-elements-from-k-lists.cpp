// @leetcode id=632 questionId=632 slug=smallest-range-covering-elements-from-k-lists lang=cpp site=leetcode.com title="Smallest Range Covering Elements from K Lists"
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // Min-heap of (value, list index, index within list); advance the
        // smallest element's pointer each step while tracking the current max.
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        int curMax = INT_MIN;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }

        int bestLo = 0, bestHi = INT_MAX;
        while (true) {
            auto [val, listIdx, idx] = pq.top(); pq.pop();
            if (curMax - val < bestHi - bestLo) {
                bestLo = val;
                bestHi = curMax;
            }
            if (idx + 1 == (int)nums[listIdx].size()) break; // one list exhausted
            int nextVal = nums[listIdx][idx + 1];
            pq.push({nextVal, listIdx, idx + 1});
            curMax = max(curMax, nextVal);
        }
        return {bestLo, bestHi};
    }
};
