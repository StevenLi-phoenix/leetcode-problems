// @leetcode id=1689 questionId=1807 slug=partitioning-into-minimum-number-of-deci-binary-numbers lang=cpp site=leetcode.com title="Partitioning Into Minimum Number Of Deci-Binary Numbers"
class Solution {
    public:
    int minPartitions(string n) {
    int mx = 0;
    for (char c : n) mx = max(mx, c - '0');
    return mx;
    }
    };
