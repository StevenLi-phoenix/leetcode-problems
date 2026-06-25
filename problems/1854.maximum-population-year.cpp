// @leetcode id=1854 questionId=1983 slug=maximum-population-year lang=cpp site=leetcode.com title="Maximum Population Year"
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);

        for (auto& log : logs) {
            diff[log[0] - 1950]++;
            diff[log[1] - 1950]--;
        }

        int maxPop = 0, maxYear = 1950;
        int currentPop = 0;

        for (int i = 0; i < 101; i++) {
            currentPop += diff[i];
            if (currentPop > maxPop) {
                maxPop = currentPop;
                maxYear = 1950 + i;
            }
        }

        return maxYear;
    }
};
