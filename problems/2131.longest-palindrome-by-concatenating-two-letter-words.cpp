// @leetcode id=2131 questionId=2237 slug=longest-palindrome-by-concatenating-two-letter-words lang=cpp site=leetcode.com title="Longest Palindrome by Concatenating Two Letter Words"
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (auto& w : words) count[w]++;

        long long total = 0;
        bool usedMiddle = false;
        for (auto& [w, cnt] : count) {
            if (w[0] == w[1]) {
                total += (cnt / 2) * 2 * 2; // pairs go on both sides
                if (cnt % 2 == 1) usedMiddle = true;
            } else {
                string rev = {w[1], w[0]};
                if (w < rev) { // count each asymmetric pair once
                    auto it = count.find(rev);
                    int other = (it != count.end()) ? it->second : 0;
                    total += (long long)min(cnt, other) * 2 * 2;
                }
            }
        }
        if (usedMiddle) total += 2;
        return (int)total;
    }
};
