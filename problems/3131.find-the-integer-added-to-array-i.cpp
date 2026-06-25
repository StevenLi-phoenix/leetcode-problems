// @leetcode id=3131 questionId=3397 slug=find-the-integer-added-to-array-i lang=cpp site=leetcode.com title="Find the Integer Added to Array I"
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(), nums2.end()) - 
               *min_element(nums1.begin(), nums1.end());
    }
};
