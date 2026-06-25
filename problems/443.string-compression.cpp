// @leetcode id=443 questionId=443 slug=string-compression lang=cpp site=leetcode.com title="String Compression"
class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;

        while (i < (int)chars.size()) {
            char c = chars[i];
            int count = 0;

            while (i < (int)chars.size() && chars[i] == c) {
                count++;
                i++;
            }

            chars[write++] = c;

            if (count > 1) {
                string count_str = to_string(count);
                for (char digit : count_str) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};
