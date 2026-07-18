// @leetcode id=2405 questionId=2487 slug=optimal-partition-of-string lang=cpp site=leetcode.com title="Optimal Partition of String"
class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        int seen = 0;

        for (char c : s) {
            int bit = 1 << (c - 'a');
            if (seen & bit) {
                count++;
                seen = 0;
            }
            seen |= bit;
        }

        return count;
    }
};
