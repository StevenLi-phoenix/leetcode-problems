// @leetcode id=598 questionId=598 slug=range-addition-ii lang=cpp site=leetcode.com title="Range Addition II"
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto& op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
