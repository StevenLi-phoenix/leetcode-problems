// @leetcode id=1863 questionId=1993 slug=sum-of-all-subset-xor-totals lang=cpp site=leetcode.com title="Sum of All Subset XOR Totals"
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // Each bit set in the OR of all elements appears in exactly half
        // of the 2^n subsets' XOR totals (with the rest cancelling out),
        // so the sum equals (OR of all elements) * 2^(n-1).
        int orAll = 0;
        for (int v : nums) orAll |= v;
        return orAll << (nums.size() - 1);
    }
};
