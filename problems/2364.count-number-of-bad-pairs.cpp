// @leetcode id=2364 questionId=2448 slug=count-number-of-bad-pairs lang=cpp site=leetcode.com title="Count Number of Bad Pairs"
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, long long> count;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            long long key = (long long)nums[i] - i;
            long long& c = count[key];
            goodPairs += c;
            c++;
        }

        long long totalPairs = (long long)n * (n - 1) / 2;
        return totalPairs - goodPairs;
    }
};
