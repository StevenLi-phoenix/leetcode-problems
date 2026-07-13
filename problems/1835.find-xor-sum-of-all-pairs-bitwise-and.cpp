// @leetcode id=1835 questionId=1963 slug=find-xor-sum-of-all-pairs-bitwise-and lang=cpp site=leetcode.com title="Find XOR Sum of All Pairs Bitwise AND"
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        // AND distributes over XOR: XOR_{i,j}(arr1[i] & arr2[j]) equals
        // (XOR of arr1) & (XOR of arr2), since each bit position's result
        // only depends on the parity of set bits contributed independently
        // by each array at that position.
        int x1 = 0, x2 = 0;
        for (int v : arr1) x1 ^= v;
        for (int v : arr2) x2 ^= v;
        return x1 & x2;
    }
};
