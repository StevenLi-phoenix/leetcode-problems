// @leetcode id=1502 questionId=1626 slug=can-make-arithmetic-progression-from-sequence lang=cpp site=leetcode.com title="Can Make Arithmetic Progression From Sequence"
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < (int)arr.size(); i++) {
            if (arr[i] - arr[i-1] != diff) return false;
        }
        return true;
    }
};
