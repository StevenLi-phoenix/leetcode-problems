// @leetcode id=2259 questionId=2337 slug=remove-digit-from-number-to-maximize-result lang=cpp site=leetcode.com title="Remove Digit From Number to Maximize Result"
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int lastPos = -1;
        
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                lastPos = i;
                // If next digit is larger, removing here gives maximum result
                if (i + 1 < n && number[i + 1] > digit) {
                    return number.substr(0, i) + number.substr(i + 1);
                }
            }
        }
        
        // Remove the last occurrence of digit
        return number.substr(0, lastPos) + number.substr(lastPos + 1);
    }
};
