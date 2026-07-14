// @leetcode id=2178 questionId=2279 slug=maximum-split-of-positive-even-integers lang=cpp site=leetcode.com title="Maximum Split of Positive Even Integers"
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0) return {};

        vector<long long> result;
        long long next = 2, remaining = finalSum;
        while (remaining >= next) {
            result.push_back(next);
            remaining -= next;
            next += 2;
        }
        result.back() += remaining;
        return result;
    }
};
