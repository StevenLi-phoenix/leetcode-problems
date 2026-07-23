// @leetcode id=1417 questionId=1532 slug=reformat-the-string lang=cpp site=leetcode.com title="Reformat The String"
class Solution {
public:
    string reformat(string s) {
        string letters, digits;
        for (char c : s) {
            if (isdigit(c)) digits += c;
            else letters += c;
        }

        if (abs((int)(letters.size() - digits.size())) > 1) return "";

        string& larger = letters.size() >= digits.size() ? letters : digits;
        string& smaller = letters.size() >= digits.size() ? digits : letters;

        string result;
        for (int i = 0; i < (int)smaller.size(); i++) {
            result += larger[i];
            result += smaller[i];
        }
        if (larger.size() > smaller.size()) result += larger.back();

        return result;
    }
};
