// @leetcode id=2358 questionId=2437 slug=maximum-number-of-groups-entering-a-competition lang=cpp site=leetcode.com title="Maximum Number of Groups Entering a Competition"
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int k = 0;
        while ((long long)(k + 1) * (k + 2) / 2 <= n) k++;
        return k;
    }
};
