// @leetcode id=56 questionId=56 slug=merge-intervals lang=cpp site=leetcode.com title="Merge Intervals"
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        for (auto& iv : intervals) {
            if (!result.empty() && iv[0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], iv[1]);
            } else {
                result.push_back(iv);
            }
        }
        return result;
    }
};
