// @leetcode id=1353 questionId=1478 slug=maximum-number-of-events-that-can-be-attended lang=cpp site=leetcode.com title="Maximum Number of Events That Can Be Attended"
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int maxDay = 0;
        for (auto& e : events) maxDay = max(maxDay, e[1]);

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i = 0, attended = 0;
        for (int day = 1; day <= maxDay; day++) {
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                i++;
            }
            while (!minHeap.empty() && minHeap.top() < day) minHeap.pop();
            if (!minHeap.empty()) {
                minHeap.pop();
                attended++;
            }
        }
        return attended;
    }
};
