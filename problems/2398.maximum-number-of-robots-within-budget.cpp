// @leetcode id=2398 questionId=2449 slug=maximum-number-of-robots-within-budget lang=cpp site=leetcode.com title="Maximum Number of Robots Within Budget"
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        deque<int> maxDeque;
        long long sumRunning = 0;
        int left = 0;
        int best = 0;

        for (int right = 0; right < n; right++) {
            sumRunning += runningCosts[right];
            while (!maxDeque.empty() && chargeTimes[maxDeque.back()] <= chargeTimes[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            while (!maxDeque.empty() &&
                   chargeTimes[maxDeque.front()] + (long long)(right - left + 1) * sumRunning > budget) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                sumRunning -= runningCosts[left];
                left++;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};
