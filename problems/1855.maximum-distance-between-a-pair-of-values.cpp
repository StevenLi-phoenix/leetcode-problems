// @leetcode id=1855 questionId=1984 slug=maximum-distance-between-a-pair-of-values lang=cpp site=leetcode.com title="Maximum Distance Between a Pair of Values"
class Solution {
    public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    int res = 0;
    int n = nums1.size(), m = nums2.size();
    while (i < n && j < m) {
    if (j < i) {
    j = i;
    }
    if (nums1[i] <= nums2[j]) {
    res = max(res, j - i);
    j++;
    } else {
    i++;
    }
    }
    return res;
    }
    };
