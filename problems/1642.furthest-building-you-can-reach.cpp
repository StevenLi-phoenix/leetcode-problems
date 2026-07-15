// @leetcode id=1642 questionId=1762 slug=furthest-building-you-can-reach lang=cpp site=leetcode.com title="Furthest Building You Can Reach"
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i + 1 < (int)heights.size(); i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) continue;
            minHeap.push(diff);
            if ((int)minHeap.size() > ladders) {
                bricks -= minHeap.top();
                minHeap.pop();
                if (bricks < 0) return i;
            }
        }
        return heights.size() - 1;
    }
};
