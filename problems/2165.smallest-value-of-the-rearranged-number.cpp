// @leetcode id=2165 questionId=2284 slug=smallest-value-of-the-rearranged-number lang=cpp site=leetcode.com title="Smallest Value of the Rearranged Number"
class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        
        // Get digits
        string s = to_string(abs(num));
        
        if (num > 0) {
            // Sort ascending
            sort(s.begin(), s.end());
            // Find first non-zero digit and swap with front
            int idx = s.find_first_not_of('0');
            if (idx != 0) {
                swap(s[0], s[idx]);
            }
            return stoll(s);
        } else {
            // Sort descending for negative (larger absolute value = smaller number)
            sort(s.begin(), s.end(), greater<char>());
            return -stoll(s);
        }
    }
};
