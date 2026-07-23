// @leetcode id=2210 questionId=2316 slug=count-hills-and-valleys-in-an-array lang=cpp site=leetcode.com title="Count Hills and Valleys in an Array"
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> comp;
        for (int x : nums) {
            if (comp.empty() || comp.back() != x) comp.push_back(x);
        }
        int count = 0;
        for (int i = 1; i + 1 < (int)comp.size(); i++) {
            bool hill = comp[i] > comp[i - 1] && comp[i] > comp[i + 1];
            bool valley = comp[i] < comp[i - 1] && comp[i] < comp[i + 1];
            if (hill || valley) count++;
        }
        return count;
    }
};
