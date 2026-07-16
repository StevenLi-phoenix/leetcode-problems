// @leetcode id=393 questionId=393 slug=utf-8-validation lang=cpp site=leetcode.com title="UTF-8 Validation"
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        int n = data.size();
        while (i < n) {
            int byte = data[i] & 0xFF;
            int numBytes;
            if ((byte & 0x80) == 0) {
                numBytes = 1;
            } else if ((byte & 0xE0) == 0xC0) {
                numBytes = 2;
            } else if ((byte & 0xF0) == 0xE0) {
                numBytes = 3;
            } else if ((byte & 0xF8) == 0xF0) {
                numBytes = 4;
            } else {
                return false;
            }
            if (i + numBytes > n) return false;
            for (int j = 1; j < numBytes; j++) {
                if ((data[i + j] & 0xC0) != 0x80) return false;
            }
            i += numBytes;
        }
        return true;
    }
};
