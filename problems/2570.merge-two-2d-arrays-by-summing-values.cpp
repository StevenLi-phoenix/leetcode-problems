// @leetcode id=2570 questionId=2707 slug=merge-two-2d-arrays-by-summing-values lang=cpp site=leetcode.com title="Merge Two 2D Arrays by Summing Values"
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < (int)nums1.size() && j < (int)nums2.size()) {
            if (nums1[i][0] < nums2[j][0]) ans.push_back(nums1[i++]);
            else if (nums1[i][0] > nums2[j][0]) ans.push_back(nums2[j++]);
            else {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++; j++;
            }
        }
        while (i < (int)nums1.size()) ans.push_back(nums1[i++]);
        while (j < (int)nums2.size()) ans.push_back(nums2[j++]);
        return ans;
    }
};
