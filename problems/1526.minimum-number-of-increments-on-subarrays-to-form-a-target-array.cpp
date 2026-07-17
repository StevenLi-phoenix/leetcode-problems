// @leetcode id=1526 questionId=1633 slug=minimum-number-of-increments-on-subarrays-to-form-a-target-array lang=cpp site=leetcode.com title="Minimum Number of Increments on Subarrays to Form a Target Array"
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long total = target[0];
        for (int i = 1; i < (int)target.size(); i++) {
            if (target[i] > target[i - 1]) total += target[i] - target[i - 1];
        }
        return (int)total;
    }
};
