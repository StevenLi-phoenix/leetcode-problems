// @leetcode id=349 questionId=349 slug=intersection-of-two-arrays lang=cpp site=leetcode.com title="Intersection of Two Arrays"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;
        for (int x : nums2) {
            if (set1.count(x)) resultSet.insert(x);
        }
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
