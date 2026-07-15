// @leetcode id=2522 questionId=2511 slug=partition-string-into-substrings-with-values-at-most-k lang=cpp site=leetcode.com title="Partition String Into Substrings With Values at Most K"
class Solution {
public:
    int minimumPartition(string s, int k) {
        int count = 1;
        long long current = 0;
        for (char c : s) {
            int digit = c - '0';
            if (digit > k) return -1;
            long long next = current * 10 + digit;
            if (next > k) {
                count++;
                current = digit;
            } else {
                current = next;
            }
        }
        return count;
    }
};
