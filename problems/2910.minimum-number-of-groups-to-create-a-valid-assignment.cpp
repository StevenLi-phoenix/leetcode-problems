// @leetcode id=2910 questionId=3166 slug=minimum-number-of-groups-to-create-a-valid-assignment lang=cpp site=leetcode.com title="Minimum Number of Groups to Create a Valid Assignment"
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int, int> freq;
        for (int b : balls) freq[b]++;

        unordered_map<int, int> countOfCount;
        int maxC = 0;
        for (auto& [val, c] : freq) {
            countOfCount[c]++;
            maxC = max(maxC, c);
        }

        int best = INT_MAX;
        for (int k = 1; k <= maxC; k++) {
            long long total = 0;
            bool feasible = true;
            for (auto& [c, numValues] : countOfCount) {
                long long g = (c + k - 1) / k;
                if (g * (k - 1) > c) {
                    feasible = false;
                    break;
                }
                total += g * numValues;
            }
            if (feasible) best = min(best, (int)total);
        }

        return best;
    }
};
