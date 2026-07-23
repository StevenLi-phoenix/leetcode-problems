// @leetcode id=344 questionId=344 slug=reverse-string lang=cpp site=leetcode.com title="Reverse String"
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
