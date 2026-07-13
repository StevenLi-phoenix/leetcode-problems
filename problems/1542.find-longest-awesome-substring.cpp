// @leetcode id=1542 questionId=1668 slug=find-longest-awesome-substring lang=cpp site=leetcode.com title="Find Longest Awesome Substring"
class Solution {
public:
    int longestAwesome(string s) {
        // A substring can be rearranged into a palindrome iff at most one
        // digit has an odd count, i.e. its parity bitmask (10 bits, one
        // per digit) has popcount <= 1. Track the running parity mask and
        // look up its first occurrence (or one with a single bit flipped)
        // to find the longest matching span.
        int n = s.size();
        vector<int> firstSeen(1024, -2); // -2 = not seen
        firstSeen[0] = -1;

        int mask = 0;
        int best = 0;
        for (int i = 0; i < n; i++) {
            mask ^= (1 << (s[i] - '0'));

            if (firstSeen[mask] != -2) best = max(best, i - firstSeen[mask]);
            for (int b = 0; b < 10; b++) {
                int m2 = mask ^ (1 << b);
                if (firstSeen[m2] != -2) best = max(best, i - firstSeen[m2]);
            }

            if (firstSeen[mask] == -2) firstSeen[mask] = i;
        }
        return best;
    }
};
