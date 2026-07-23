// @leetcode id=1128 questionId=1227 slug=number-of-equivalent-domino-pairs lang=cpp site=leetcode.com title="Number of Equivalent Domino Pairs"
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0};
        int total = 0;

        for (auto& d : dominoes) {
            int a = min(d[0], d[1]), b = max(d[0], d[1]);
            int code = a * 10 + b;
            total += count[code];
            count[code]++;
        }

        return total;
    }
};
