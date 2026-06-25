// @leetcode id=2075 questionId=2197 slug=decode-the-slanted-ciphertext lang=cpp site=leetcode.com title="Decode the Slanted Ciphertext"
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty() || rows == 1) return encodedText;
        
        int cols = encodedText.size() / rows;
        string result;
        
        // Each diagonal starts at column c in row 0
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows && c + r < cols; r++) {
                result += encodedText[r * cols + c + r];
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ')
            result.pop_back();
        
        return result;
    }
};
