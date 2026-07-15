// @leetcode id=1432 questionId=1529 slug=max-difference-you-can-get-from-changing-an-integer lang=cpp site=leetcode.com title="Max Difference You Can Get From Changing an Integer"
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        char targetX = 0;
        for (char c : s) {
            if (c != '9') { targetX = c; break; }
        }
        if (targetX != 0) {
            for (char& c : a) if (c == targetX) c = '9';
        }

        if (s[0] != '1') {
            char x = s[0];
            for (char& c : b) if (c == x) c = '1';
        } else {
            char targetY = 0;
            for (size_t i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != s[0]) { targetY = s[i]; break; }
            }
            if (targetY != 0) {
                for (size_t i = 1; i < b.size(); i++) if (b[i] == targetY) b[i] = '0';
            }
        }

        return stoi(a) - stoi(b);
    }
};
