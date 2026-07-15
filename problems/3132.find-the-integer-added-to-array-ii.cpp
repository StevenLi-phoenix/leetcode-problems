// @leetcode id=3132 questionId=3399 slug=find-the-integer-added-to-array-ii lang=cpp site=leetcode.com title="Find the Integer Added to Array II"
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int best = INT_MAX;
        for (int i = 0; i < 3 && i < (int)nums1.size(); i++) {
            int x = nums2[0] - nums1[i];
            if (check(nums1, nums2, x)) {
                best = min(best, x);
            }
        }
        return best;
    }

private:
    bool check(vector<int>& nums1, vector<int>& nums2, int x) {
        int i = 0, j = 0, skips = 0;
        int n = nums1.size(), m = nums2.size();
        while (j < m) {
            if (i >= n) return false;
            if (nums1[i] + x == nums2[j]) {
                i++;
                j++;
            } else {
                i++;
                skips++;
                if (skips > 2) return false;
            }
        }
        int leftover = n - i;
        return skips + leftover == 2;
    }
};
