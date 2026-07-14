// @leetcode id=1304 questionId=1426 slug=find-n-unique-integers-sum-up-to-zero lang=cpp site=leetcode.com title="Find N Unique Integers Sum up to Zero"
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2 == 1) result.push_back(0);
        return result;
    }
};
