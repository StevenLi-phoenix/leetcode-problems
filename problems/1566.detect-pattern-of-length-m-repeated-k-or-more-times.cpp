// @leetcode id=1566 questionId=1689 slug=detect-pattern-of-length-m-repeated-k-or-more-times lang=cpp site=leetcode.com title="Detect Pattern of Length M Repeated K or More Times"
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int needed = m * k;

        for (int i = 0; i + needed <= n; i++) {
            bool valid = true;
            for (int j = 0; j < m * (k - 1); j++) {
                if (arr[i + j] != arr[i + j + m]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }

        return false;
    }
};
