// @leetcode id=2729 questionId=2824 slug=check-if-the-number-is-fascinating lang=cpp site=leetcode.com title="Check if The Number is Fascinating"
class Solution {
public:
    bool isFascinating(int n) {
        string concat = to_string(n) + to_string(2 * n) + to_string(3 * n);
        if (concat.size() != 9) return false;

        int count[10] = {0};
        for (char c : concat) count[c - '0']++;

        if (count[0] > 0) return false;
        for (int d = 1; d <= 9; d++) {
            if (count[d] != 1) return false;
        }
        return true;
    }
};
