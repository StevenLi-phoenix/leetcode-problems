// @leetcode id=621 questionId=621 slug=task-scheduler lang=cpp site=leetcode.com title="Task Scheduler"
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for (char c : tasks) count[c - 'A']++;

        int maxFreq = 0;
        for (int c : count) maxFreq = max(maxFreq, c);

        int maxCount = 0;
        for (int c : count) if (c == maxFreq) maxCount++;

        int framework = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), framework);
    }
};
