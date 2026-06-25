// @leetcode id=3941 questionId=4313 slug=password-strength lang=cpp site=leetcode.com title="Password Strength"
class Solution {
public:
    int passwordStrength(string password) {
        set<char> lower, upper, digits, special;
        string specChars = "!@#$";
        
        for (char c : password) {
            if (islower(c)) lower.insert(c);
            else if (isupper(c)) upper.insert(c);
            else if (isdigit(c)) digits.insert(c);
            else if (specChars.find(c) != string::npos) special.insert(c);
        }
        
        return lower.size() * 1 + upper.size() * 2 + digits.size() * 3 + special.size() * 5;
    }
};
