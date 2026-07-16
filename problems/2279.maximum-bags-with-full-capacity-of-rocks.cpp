// @leetcode id=2279 questionId=2366 slug=maximum-bags-with-full-capacity-of-rocks lang=cpp site=leetcode.com title="Maximum Bags With Full Capacity of Rocks"
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> need(n);
        for (int i = 0; i < n; i++) need[i] = capacity[i] - rocks[i];
        sort(need.begin(), need.end());

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (need[i] <= additionalRocks) {
                additionalRocks -= need[i];
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
