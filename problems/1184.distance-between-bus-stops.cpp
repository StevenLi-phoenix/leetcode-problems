// @leetcode id=1184 questionId=1287 slug=distance-between-bus-stops lang=cpp site=leetcode.com title="Distance Between Bus Stops"
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);

        int forward = 0;
        for (int i = start; i < destination; i++) forward += distance[i];

        int total = 0;
        for (int d : distance) total += d;

        return min(forward, total - forward);
    }
};
