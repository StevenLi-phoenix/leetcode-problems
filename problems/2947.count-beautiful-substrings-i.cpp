// @leetcode id=2947 questionId=3210 slug=count-beautiful-substrings-i lang=cpp site=leetcode.com title="Count Beautiful Substrings I"
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        string vowels = "aeiou";
        auto isVowel = [&](char c) {
            return vowels.find(c) != string::npos;
        };
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            int v = 0, c = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) v++;
                else c++;
                if (v == c && (v * c) % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
