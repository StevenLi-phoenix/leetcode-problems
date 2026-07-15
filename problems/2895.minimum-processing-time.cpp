// @leetcode id=2895 questionId=3151 slug=minimum-processing-time lang=cpp site=leetcode.com title="Minimum Processing Time"
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());

        int result = 0;
        for (size_t i = 0; i < processorTime.size(); i++) {
            int hardestTask = tasks[i * 4];
            result = max(result, processorTime[i] + hardestTask);
        }
        return result;
    }
};
