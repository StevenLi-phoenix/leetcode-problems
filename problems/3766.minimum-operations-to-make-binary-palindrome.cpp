// @leetcode id=3766 questionId=4099 slug=minimum-operations-to-make-binary-palindrome lang=cpp site=leetcode.com title="Minimum Operations to Make Binary Palindrome"
class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        while (x > 0) { s += ('0' + (x & 1)); x >>= 1; }
        reverse(s.begin(), s.end());
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            int d = 0;
            while (true) {
                if (num - d >= 1 && isPalindrome(num - d)) { result.push_back(d); break; }
                if (isPalindrome(num + d)) { result.push_back(d); break; }
                d++;
            }
        }
        return result;
    }
};
