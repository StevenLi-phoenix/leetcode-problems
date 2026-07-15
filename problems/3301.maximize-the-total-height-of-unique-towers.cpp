// @leetcode id=3301 questionId=3510 slug=maximize-the-total-height-of-unique-towers lang=cpp site=leetcode.com title="Maximize the Total Height of Unique Towers"
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long total = 0;
        long long prev = LLONG_MAX;
        for (int h : maximumHeight) {
            long long assigned = min((long long)h, prev - 1);
            if (assigned <= 0) return -1;
            total += assigned;
            prev = assigned;
        }
        return total;
    }
};
