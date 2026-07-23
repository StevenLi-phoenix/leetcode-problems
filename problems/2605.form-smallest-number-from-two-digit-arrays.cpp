// @leetcode id=2605 questionId=2668 slug=form-smallest-number-from-two-digit-arrays lang=cpp site=leetcode.com title="Form Smallest Number From Two Digit Arrays"
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        int commonMin = 10;
        for (int x : nums2) {
            if (set1.count(x)) commonMin = min(commonMin, x);
        }
        if (commonMin < 10) return commonMin;

        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        int smaller = min(min1, min2), larger = max(min1, min2);
        return smaller * 10 + larger;
    }
};
