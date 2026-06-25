// @leetcode id=1578 questionId=1700 slug=minimum-time-to-make-rope-colorful lang=cpp site=leetcode.com title="Minimum Time to Make Rope Colorful"
class Solution {
    public:
    int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size(), ans = 0;
    int i = 0;
    while (i < n) {
    int j = i;
    int sum = 0, mx = 0;
    while (j < n && colors[j] == colors[i]) {
    sum += neededTime[j];
    mx = max(mx, neededTime[j]);
    j++;
    }
    ans += sum - mx;
    i = j;
    }
    return ans;
    }
    };
