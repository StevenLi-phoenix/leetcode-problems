// @leetcode id=3767 questionId=4089 slug=maximize-points-after-choosing-k-tasks lang=cpp site=leetcode.com title="Maximize Points After Choosing K Tasks"
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long total = 0;
        int preferT1Count = 0;
        vector<int> negDiffs; // technique1[i] - technique2[i] < 0, sorted desc (least negative first)

        for (int i = 0; i < n; i++) {
            int diff = technique1[i] - technique2[i];
            if (diff >= 0) {
                total += technique1[i];
                preferT1Count++;
            } else {
                total += technique2[i];
                negDiffs.push_back(diff);
            }
        }

        if (preferT1Count < k) {
            int needed = k - preferT1Count;
            sort(negDiffs.begin(), negDiffs.end(), greater<int>());
            for (int i = 0; i < needed; i++) total += negDiffs[i];
        }
        return total;
    }
};
