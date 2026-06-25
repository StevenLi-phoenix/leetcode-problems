// @leetcode id=2161 questionId=2265 slug=partition-array-according-to-given-pivot lang=cpp site=leetcode.com title="Partition Array According to Given Pivot"
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        for (int n : nums) {
            if (n < pivot) less.push_back(n);
            else if (n == pivot) equal.push_back(n);
            else greater.push_back(n);
        }
        vector<int> res;
        for (int n : less) res.push_back(n);
        for (int n : equal) res.push_back(n);
        for (int n : greater) res.push_back(n);
        return res;
    }
};
