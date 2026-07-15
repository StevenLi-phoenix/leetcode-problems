// @leetcode id=2177 questionId=2278 slug=find-three-consecutive-integers-that-sum-to-a-given-number lang=cpp site=leetcode.com title="Find Three Consecutive Integers That Sum to a Given Number"
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0) return {};
        long long mid = num / 3;
        return {mid - 1, mid, mid + 1};
    }
};
