// @leetcode id=869 questionId=900 slug=reordered-power-of-2 lang=cpp site=leetcode.com title="Reordered Power of 2"
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Get digits of n sorted
        vector<int> digits;
        int temp = n;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        sort(digits.begin(), digits.end());
        
        // Check all powers of 2 up to 10^9
        for (int i = 0; i < 31; i++) {
            long long power = 1LL << i;
            
            // Get digits of power
            vector<int> powerDigits;
            long long temp = power;
            while (temp > 0) {
                powerDigits.push_back(temp % 10);
                temp /= 10;
            }
            sort(powerDigits.begin(), powerDigits.end());
            
            // Compare
            if (digits == powerDigits) {
                return true;
            }
        }
        
        return false;
    }
};
