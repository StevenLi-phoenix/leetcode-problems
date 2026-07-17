// @leetcode id=1915 questionId=2044 slug=number-of-wonderful-substrings lang=cpp site=leetcode.com title="Number of Wonderful Substrings"
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0);
        count[0] = 1;
        int mask = 0;
        long long result = 0;

        for (char c : word) {
            mask ^= (1 << (c - 'a'));
            result += count[mask];
            for (int b = 0; b < 10; b++) {
                result += count[mask ^ (1 << b)];
            }
            count[mask]++;
        }
        return result;
    }
};
