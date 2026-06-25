// @leetcode id=17 questionId=17 slug=letter-combinations-of-a-phone-number lang=cpp site=leetcode.com title="Letter Combinations of a Phone Number"
class Solution {
private:
    vector<string> result;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtrack(const string& digits, int index, string current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        for (char c : letters) {
            backtrack(digits, index + 1, current + c);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        
        backtrack(digits, 0, "");
        return result;
    }
};
