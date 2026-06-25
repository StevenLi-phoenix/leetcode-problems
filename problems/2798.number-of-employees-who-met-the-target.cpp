// @leetcode id=2798 questionId=2876 slug=number-of-employees-who-met-the-target lang=cpp site=leetcode.com title="Number of Employees Who Met the Target"
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for (int h : hours) {
            if (h >= target) count++;
        }
        return count;
    }
};
