// @leetcode id=2843 questionId=2998 slug=count-symmetric-integers lang=cpp site=leetcode.com title="  Count Symmetric Integers"
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int x = low; x <= high; x++) {
            string s = to_string(x);
            int n = s.size();
            if (n % 2 != 0) continue;
            int half = n / 2;
            int left = 0, right = 0;
            for (int i = 0; i < half; i++) left += s[i] - '0';
            for (int i = half; i < n; i++) right += s[i] - '0';
            if (left == right) count++;
        }
        return count;
    }
};
