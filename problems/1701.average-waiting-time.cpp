// @leetcode id=1701 questionId=1803 slug=average-waiting-time lang=cpp site=leetcode.com title="Average Waiting Time"
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long currentTime = 0;
        long long totalWait = 0;
        for (auto& c : customers) {
            long long arrival = c[0], duration = c[1];
            currentTime = max(currentTime, arrival) + duration;
            totalWait += currentTime - arrival;
        }
        return (double)totalWait / customers.size();
    }
};
