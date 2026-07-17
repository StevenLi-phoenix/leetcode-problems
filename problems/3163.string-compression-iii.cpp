// @leetcode id=3163 questionId=3451 slug=string-compression-iii lang=cpp site=leetcode.com title="String Compression III"
class Solution {
public:
    string compressedString(string word) {
        string result;
        int n = word.size();
        int i = 0;
        while (i < n) {
            char c = word[i];
            int j = i;
            while (j < n && word[j] == c && j - i < 9) j++;
            result += to_string(j - i);
            result += c;
            i = j;
        }
        return result;
    }
};
