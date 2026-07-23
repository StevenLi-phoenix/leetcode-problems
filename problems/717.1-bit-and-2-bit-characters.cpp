// @leetcode id=717 questionId=717 slug=1-bit-and-2-bit-characters lang=cpp site=leetcode.com title="1-bit and 2-bit Characters"
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n - 1) {
            if (bits[i] == 1) i += 2;
            else i += 1;
        }
        return i == n - 1;
    }
};
