// @leetcode id=1702 questionId=1804 slug=maximum-binary-string-after-change lang=cpp site=leetcode.com title="Maximum Binary String After Change"
class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        // Count leading 1s
        int p = 0;
        while (p < n && binary[p] == '1') p++;
        
        // If all ones, return as is
        if (p == n) return binary;
        
        // Count zeros and ones in suffix starting at p
        int zeros = 0, ones_in_suffix = 0;
        for (int i = p; i < n; i++) {
            if (binary[i] == '0') zeros++;
            else ones_in_suffix++;
        }
        
        // Result: p ones + (zeros-1) ones + '0' + ones_in_suffix ones
        string result = "";
        result += string(p, '1');
        result += string(zeros - 1, '1');
        result += '0';
        result += string(ones_in_suffix, '1');
        return result;
    }
};
