// @leetcode id=38 questionId=38 slug=count-and-say lang=cpp site=leetcode.com title="Count and Say"
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string next;
            int j = 0;
            int len = s.size();
            while (j < len) {
                int k = j;
                while (k < len && s[k] == s[j]) ++k;
                next += to_string(k - j);
                next += s[j];
                j = k;
            }
            s = next;
        }
        return s;
    }
};
