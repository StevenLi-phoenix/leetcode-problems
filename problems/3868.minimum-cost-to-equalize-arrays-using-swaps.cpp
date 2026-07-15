// @leetcode id=3868 questionId=4253 slug=minimum-cost-to-equalize-arrays-using-swaps lang=cpp site=leetcode.com title="Minimum Cost to Equalize Arrays Using Swaps"
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1, total;
        for (int x : nums1) { count1[x]++; total[x]++; }
        for (int x : nums2) { total[x]++; }

        int cost = 0;
        for (auto& [v, tot] : total) {
            if (tot % 2 != 0) return -1;
            int target = tot / 2;
            int have1 = count1.count(v) ? count1[v] : 0;
            if (have1 > target) cost += have1 - target;
        }
        return cost;
    }
};
