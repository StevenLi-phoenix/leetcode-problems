// @leetcode id=871 questionId=902 slug=minimum-number-of-refueling-stops lang=cpp site=leetcode.com title="Minimum Number of Refueling Stops"
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        long long fuel = startFuel;
        int stops = 0;
        int i = 0;
        int n = stations.size();

        while (fuel < target) {
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            if (maxHeap.empty()) return -1;
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }

        return stops;
    }
};
