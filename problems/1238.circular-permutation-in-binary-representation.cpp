// @leetcode id=1238 questionId=1359 slug=circular-permutation-in-binary-representation lang=cpp site=leetcode.com title="Circular Permutation in Binary Representation"
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int size = 1 << n;
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            result[i] = (i ^ (i >> 1)) ^ start;
        }
        return result;
    }
};
