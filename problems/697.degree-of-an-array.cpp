// @leetcode id=697 questionId=697 slug=degree-of-an-array lang=cpp site=leetcode.com title="Degree of an Array"
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> first, count;
        int maxFreq = 0, best = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i];
            if (!first.count(x)) first[x] = i;
            count[x]++;

            if (count[x] > maxFreq) {
                maxFreq = count[x];
                best = i - first[x] + 1;
            } else if (count[x] == maxFreq) {
                best = min(best, i - first[x] + 1);
            }
        }
        return best;
    }
};
