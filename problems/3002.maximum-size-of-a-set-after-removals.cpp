// @leetcode id=3002 questionId=3228 slug=maximum-size-of-a-set-after-removals lang=cpp site=leetcode.com title="Maximum Size of a Set After Removals"
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int half = n / 2;

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        int common = 0;
        for (int v : set1) {
            if (set2.count(v)) ++common;
        }

        int unique1 = set1.size() - common;
        int unique2 = set2.size() - common;

        int keep1 = min(unique1, half);
        int keep2 = min(unique2, half);
        int leftover = (half - keep1) + (half - keep2);

        return keep1 + keep2 + min(common, leftover);
    }
};
