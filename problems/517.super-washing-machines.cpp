// @leetcode id=517 questionId=517 slug=super-washing-machines lang=cpp site=leetcode.com title="Super Washing Machines"
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        long long total = 0;
        for (int m : machines) total += m;
        if (total % n != 0) return -1;

        long long avg = total / n;
        long long runningFlow = 0;
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            long long diff = machines[i] - avg;
            runningFlow += diff;
            answer = max({answer, abs(runningFlow), diff});
        }

        return (int)answer;
    }
};
