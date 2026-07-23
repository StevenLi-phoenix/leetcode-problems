// @leetcode id=1491 questionId=1584 slug=average-salary-excluding-the-minimum-and-maximum-salary lang=cpp site=leetcode.com title="Average Salary Excluding the Minimum and Maximum Salary"
class Solution {
public:
    double average(vector<int>& salary) {
        int mn = *min_element(salary.begin(), salary.end());
        int mx = *max_element(salary.begin(), salary.end());

        long long sum = 0;
        int count = 0;
        for (int s : salary) {
            if (s == mn || s == mx) continue;
            sum += s;
            count++;
        }
        return (double)sum / count;
    }
};
