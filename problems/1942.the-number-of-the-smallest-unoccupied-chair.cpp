// @leetcode id=1942 questionId=2054 slug=the-number-of-the-smallest-unoccupied-chair lang=cpp site=leetcode.com title="The Number of the Smallest Unoccupied Chair"
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            return times[a][0] < times[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> freeChairs;
        for (int i = 0; i < n; i++) freeChairs.push(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied; // (leaveTime, chair)

        for (int idx : order) {
            int arrival = times[idx][0], leave = times[idx][1];
            while (!occupied.empty() && occupied.top().first <= arrival) {
                freeChairs.push(occupied.top().second);
                occupied.pop();
            }
            int chair = freeChairs.top(); freeChairs.pop();
            if (idx == targetFriend) return chair;
            occupied.push({leave, chair});
        }
        return -1;
    }
};
