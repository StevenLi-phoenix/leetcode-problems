// @leetcode id=345 questionId=345 slug=reverse-vowels-of-a-string lang=cpp site=leetcode.com title="Reverse Vowels of a String"
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isVowel(s[left])) { left++; continue; }
            if (!isVowel(s[right])) { right--; continue; }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
