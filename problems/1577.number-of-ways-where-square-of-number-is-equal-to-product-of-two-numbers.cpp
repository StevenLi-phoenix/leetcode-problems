// @leetcode id=1577 questionId=1699 slug=number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers lang=cpp site=leetcode.com title="Number of Ways Where Square of Number Is Equal to Product of Two Numbers"
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return countType(nums1, nums2) + countType(nums2, nums1);
    }

private:
    int countType(vector<int>& a, vector<int>& b) {
        unordered_map<long long, int> pairProduct;
        for (int j = 0; j < (int)b.size(); ++j) {
            for (int k = j + 1; k < (int)b.size(); ++k) {
                ++pairProduct[(long long)b[j] * b[k]];
            }
        }

        int count = 0;
        for (long long x : a) {
            auto it = pairProduct.find(x * x);
            if (it != pairProduct.end()) count += it->second;
        }
        return count;
    }
};
