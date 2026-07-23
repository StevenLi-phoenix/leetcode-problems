// @leetcode id=3861 questionId=4247 slug=minimum-capacity-box lang=cpp site=leetcode.com title="Minimum Capacity Box"
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int bestIdx = -1, bestCap = INT_MAX;
        for (int i = 0; i < (int)capacity.size(); i++) {
            if (capacity[i] >= itemSize && capacity[i] < bestCap) {
                bestCap = capacity[i];
                bestIdx = i;
            }
        }
        return bestIdx;
    }
};
