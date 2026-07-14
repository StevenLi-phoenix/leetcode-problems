// @leetcode id=2442 questionId=2525 slug=count-number-of-distinct-integers-after-reverse-operations lang=cpp site=leetcode.com title="Count Number of Distinct Integers After Reverse Operations"
class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x : nums) s.insert(reverseNum(x));
        return s.size();
    }
};
