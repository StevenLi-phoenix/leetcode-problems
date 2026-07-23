// @leetcode id=2432 questionId=2518 slug=the-employee-that-worked-on-the-longest-task lang=cpp site=leetcode.com title="The Employee That Worked on the Longest Task"
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int bestId = logs[0][0];
        int bestDuration = logs[0][1];
        int prevTime = 0;

        for (auto& log : logs) {
            int id = log[0], leaveTime = log[1];
            int duration = leaveTime - prevTime;
            if (duration > bestDuration || (duration == bestDuration && id < bestId)) {
                bestDuration = duration;
                bestId = id;
            }
            prevTime = leaveTime;
        }
        return bestId;
    }
};
