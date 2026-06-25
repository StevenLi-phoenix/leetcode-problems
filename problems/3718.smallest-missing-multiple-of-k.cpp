// @leetcode id=3718 questionId=4080 slug=smallest-missing-multiple-of-k lang=cpp site=leetcode.com title="Smallest Missing Multiple of K"
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int multiple = k;
        while (numSet.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};
