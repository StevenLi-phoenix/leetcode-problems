// @leetcode id=481 questionId=481 slug=magical-string lang=cpp site=leetcode.com title="Magical String"
class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        vector<int> s(n + 1);
        s[0] = 1; s[1] = 2; s[2] = 2;
        int i = 2; // index into s being read to decide next group's length
        int size = 3;
        int nextChar = 1;
        while (size < n) {
            int groupLen = s[i];
            for (int k = 0; k < groupLen && size < n; k++) {
                s[size++] = nextChar;
            }
            nextChar = 3 - nextChar;
            i++;
        }

        int count = 0;
        for (int idx = 0; idx < n; idx++) if (s[idx] == 1) count++;
        return count;
    }
};
