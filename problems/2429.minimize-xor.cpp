// @leetcode id=2429 questionId=2509 slug=minimize-xor lang=cpp site=leetcode.com title="Minimize XOR"
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNeeded = __builtin_popcount(num2);
        int result = 0;
        
        // Try to turn off high-order bits from num1
        for (int i = 31; i >= 0 && setBitsNeeded > 0; i--) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                setBitsNeeded--;
            }
        }
        
        // If we still need more set bits, set them from LSB
        for (int i = 0; i < 32 && setBitsNeeded > 0; i++) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                setBitsNeeded--;
            }
        }
        
        return result;
    }
};
