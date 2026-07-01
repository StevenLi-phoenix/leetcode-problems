// @leetcode id=3258 questionId=3543 slug=count-substrings-that-satisfy-k-constraint-i lang=cpp site=leetcode.com title="Count Substrings That Satisfy K-Constraint I"
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int count[2] = {0, 0};
        int left = 0;
        int total = 0;
        for (int right = 0; right < n; right++) {
            count[s[right] - '0']++;
            while (count[0] > k && count[1] > k) {
                count[s[left] - '0']--;
                left++;
            }
            total += right - left + 1;
        }
        return total;
    }
};
