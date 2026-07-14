// @leetcode id=1371 questionId=1473 slug=find-the-longest-substring-containing-vowels-in-even-counts lang=cpp site=leetcode.com title="Find the Longest Substring Containing Vowels in Even Counts"
class Solution {
public:
    int findTheLongestSubstring(string s) {
        auto vowelBit = [](char c) -> int {
            switch (c) {
                case 'a': return 0;
                case 'e': return 1;
                case 'i': return 2;
                case 'o': return 3;
                case 'u': return 4;
                default: return -1;
            }
        };

        vector<int> firstSeen(32, -2); // -2 = not seen yet
        firstSeen[0] = -1;
        int mask = 0, best = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int b = vowelBit(s[i]);
            if (b >= 0) mask ^= (1 << b);
            if (firstSeen[mask] == -2) firstSeen[mask] = i;
            else best = max(best, i - firstSeen[mask]);
        }
        return best;
    }
};
