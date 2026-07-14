// @leetcode id=831 questionId=858 slug=masking-personal-information lang=cpp site=leetcode.com title="Masking Personal Information"
class Solution {
public:
    string maskPII(string s) {
        if (isalpha((unsigned char)s[0])) {
            int at = s.find('@');
            string name = s.substr(0, at);
            string domain = s.substr(at + 1);
            for (char& c : name) c = tolower((unsigned char)c);
            for (char& c : domain) c = tolower((unsigned char)c);
            return name[0] + string("*****") + name.back() + "@" + domain;
        }

        string digits;
        for (char c : s) if (isdigit((unsigned char)c)) digits += c;

        string local10 = digits.substr(digits.size() - 10);
        string last4 = local10.substr(6);
        string masked = "***-***-" + last4;

        int countryLen = digits.size() - 10;
        if (countryLen == 0) return masked;
        string country(countryLen, '*');
        return "+" + country + "-" + masked;
    }
};
