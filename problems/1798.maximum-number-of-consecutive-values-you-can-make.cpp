// @leetcode id=1798 questionId=1930 slug=maximum-number-of-consecutive-values-you-can-make lang=cpp site=leetcode.com title="Maximum Number of Consecutive Values You Can Make"
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        long long reach = 1;
        for (int c : coins) {
            if (c > reach) break;
            reach += c;
        }
        return (int)reach;
    }
};
