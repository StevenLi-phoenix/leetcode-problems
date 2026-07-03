// @leetcode id=2956 questionId=3206 slug=find-common-elements-between-two-arrays lang=cpp site=leetcode.com title="Find Common Elements Between Two Arrays"
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        int answer1 = 0, answer2 = 0;
        for (int v : nums1) if (set2.count(v)) ++answer1;
        for (int v : nums2) if (set1.count(v)) ++answer2;

        return {answer1, answer2};
    }
};
