// @leetcode id=2384 questionId=2475 slug=largest-palindromic-number lang=cpp site=leetcode.com title="Largest Palindromic Number"
class Solution {
public:
    string largestPalindromic(string num) {
        int count[10] = {0};
        for (char c : num) count[c - '0']++;

        string half;
        for (int d = 9; d >= 0; d--) {
            half += string(count[d] / 2, '0' + d);
        }

        // strip leading zeros from half (they'd become leading zeros overall)
        int start = 0;
        while (start < (int)half.size() - 1 && half[start] == '0') start++;
        if (half.empty()) start = 0;
        half = half.substr(start);
        if (half == "0") half = "";

        int mid = -1;
        for (int d = 9; d >= 0; d--) {
            if (count[d] % 2 == 1) { mid = d; break; }
        }

        string result = half;
        if (mid != -1) result += char('0' + mid);
        string rev = half;
        reverse(rev.begin(), rev.end());
        result += rev;

        if (result.empty()) return "0";
        return result;
    }
};
