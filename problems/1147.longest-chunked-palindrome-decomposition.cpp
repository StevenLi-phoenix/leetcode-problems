// @leetcode id=1147 questionId=1251 slug=longest-chunked-palindrome-decomposition lang=cpp site=leetcode.com title="Longest Chunked Palindrome Decomposition"
class Solution {
public:
    int longestDecomposition(string text) {
        int left = 0, right = (int)text.size() - 1;
        int count = 0;
        while (left < right) {
            bool matched = false;
            for (int len = 1; left + len - 1 < right - len + 1; ++len) {
                if (text.compare(left, len, text, right - len + 1, len) == 0) {
                    count += 2;
                    left += len;
                    right -= len;
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                ++count;
                break;
            }
        }
        if (left == right) ++count;
        return count;
    }
};
