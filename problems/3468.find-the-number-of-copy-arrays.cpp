// @leetcode id=3468 questionId=3785 slug=find-the-number-of-copy-arrays lang=cpp site=leetcode.com title="Find the Number of Copy Arrays"
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        long long lo = bounds[0][0], hi = bounds[0][1];
        for (int i = 1; i < (int)original.size(); i++) {
            long long diff = (long long)original[i] - original[0];
            lo = max(lo, (long long)bounds[i][0] - diff);
            hi = min(hi, (long long)bounds[i][1] - diff);
        }
        return (int)max(0LL, hi - lo + 1);
    }
};
