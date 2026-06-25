// @leetcode id=3079 questionId=3367 slug=find-the-sum-of-encrypted-integers lang=cpp site=leetcode.com title="Find the Sum of Encrypted Integers"
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            // Find max digit and count of digits
            int maxDigit = 0, numDigits = 0, temp = num;
            while (temp > 0) {
                maxDigit = max(maxDigit, temp % 10);
                numDigits++;
                temp /= 10;
            }
            // Build encrypted number: all digits = maxDigit
            int encrypted = 0, multiplier = 1;
            for (int i = 0; i < numDigits; i++) {
                encrypted += maxDigit * multiplier;
                multiplier *= 10;
            }
            total += encrypted;
        }
        return total;
    }
};
