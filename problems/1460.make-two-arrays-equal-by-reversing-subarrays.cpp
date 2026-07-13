// @leetcode id=1460 questionId=1556 slug=make-two-arrays-equal-by-reversing-subarrays lang=cpp site=leetcode.com title="Make Two Arrays Equal by Reversing Subarrays"
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
