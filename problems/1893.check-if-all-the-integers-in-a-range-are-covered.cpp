// @leetcode id=1893 questionId=2005 slug=check-if-all-the-integers-in-a-range-are-covered lang=cpp site=leetcode.com title="Check if All the Integers in a Range Are Covered"
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> covered(52, false);

        for (auto& range : ranges) {
            for (int i = range[0]; i <= range[1]; i++) {
                covered[i] = true;
            }
        }

        for (int i = left; i <= right; i++) {
            if (!covered[i]) {
                return false;
            }
        }

        return true;
    }
};
