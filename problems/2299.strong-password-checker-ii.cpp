// @leetcode id=2299 questionId=2391 slug=strong-password-checker-ii lang=cpp site=leetcode.com title="Strong Password Checker II"
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        string special = "!@#$%^&*()-+";
        
        for (int i = 0; i < (int)password.size(); i++) {
            char c = password[i];
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
            if (special.find(c) != string::npos) hasSpecial = true;
            if (i > 0 && password[i] == password[i-1]) return false;
        }
        
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};
