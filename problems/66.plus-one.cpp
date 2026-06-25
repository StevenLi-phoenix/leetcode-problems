// @leetcode id=66 questionId=66 slug=plus-one lang=cpp site=leetcode.com title="Plus One"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0; // 9 + 1 => 0 carry continues
        }
        
        // If we got here, all digits were 9 (e.g., 999 -> 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
