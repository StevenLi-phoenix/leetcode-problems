// @leetcode id=1694 questionId=1812 slug=reformat-phone-number lang=cpp site=leetcode.com title="Reformat Phone Number"
class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char c : number) if (isdigit((unsigned char)c)) digits += c;

        vector<string> blocks;
        int i = 0, n = digits.size();
        while (n - i > 4) {
            blocks.push_back(digits.substr(i, 3));
            i += 3;
        }
        int rem = n - i;
        if (rem == 4) {
            blocks.push_back(digits.substr(i, 2));
            blocks.push_back(digits.substr(i + 2, 2));
        } else {
            blocks.push_back(digits.substr(i, rem));
        }

        string result;
        for (int j = 0; j < (int)blocks.size(); j++) {
            if (j > 0) result += '-';
            result += blocks[j];
        }
        return result;
    }
};
