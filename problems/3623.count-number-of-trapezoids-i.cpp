// @leetcode id=3623 questionId=3886 slug=count-number-of-trapezoids-i lang=cpp site=leetcode.com title="Count Number of Trapezoids I"
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> countByY;
        for (auto& p : points) countByY[p[1]]++;

        long long runningSum = 0, answer = 0;
        for (auto& [y, cnt] : countByY) {
            long long pairs = (cnt * (cnt - 1) / 2) % MOD;
            answer = (answer + pairs * runningSum) % MOD;
            runningSum = (runningSum + pairs) % MOD;
        }
        return (int)answer;
    }
};
