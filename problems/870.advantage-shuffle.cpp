// @leetcode id=870 questionId=901 slug=advantage-shuffle lang=cpp site=leetcode.com title="Advantage Shuffle"
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        multiset<int> sorted1(nums1.begin(), nums1.end());

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] > nums2[b]; });

        vector<int> result(n);
        for (int i : idx) {
            auto it = sorted1.upper_bound(nums2[i]);
            if (it == sorted1.end()) {
                result[i] = *sorted1.begin();
                sorted1.erase(sorted1.begin());
            } else {
                result[i] = *it;
                sorted1.erase(it);
            }
        }
        return result;
    }
};
