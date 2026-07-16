// @leetcode id=2365 questionId=2483 slug=task-scheduler-ii lang=cpp site=leetcode.com title="Task Scheduler II"
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> lastDay;
        long long day = 0;

        for (int t : tasks) {
            day++;
            auto it = lastDay.find(t);
            if (it != lastDay.end()) {
                long long earliest = it->second + space + 1;
                if (day < earliest) day = earliest;
            }
            lastDay[t] = day;
        }
        return day;
    }
};
