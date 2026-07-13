// @leetcode id=556 questionId=556 slug=next-greater-element-iii lang=cpp site=leetcode.com title="Next Greater Element III"
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (!next_permutation(s.begin(), s.end())) return -1;
        try {
            long long result = stoll(s);
            if (result > INT_MAX) return -1;
            return (int)result;
        } catch (...) {
            return -1;
        }
    }
};
