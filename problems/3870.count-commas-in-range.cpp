// @leetcode id=3870 questionId=4245 slug=count-commas-in-range lang=cpp site=leetcode.com title="Count Commas in Range"
class Solution {
public:
    int countCommas(int n) {
        // Numbers with 1 comma: 1000 to min(n, 999999)
        // Numbers with 2 commas: 1000000 to min(n, 999999999)
        // etc.
        // Since n <= 10^5, only 1-comma numbers exist
        // Count = max(0, n - 999)
        int count = 0;
        // 1 comma: [1000, 999999]
        if (n >= 1000) count += min(n, 999999) - 1000 + 1;
        // 2 commas: [1000000, 999999999] - but n <= 10^5 so this is 0
        if (n >= 1000000) count += min(n, 999999999) - 1000000 + 1;
        return count;
    }
};
