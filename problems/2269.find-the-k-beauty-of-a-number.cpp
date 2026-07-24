// @leetcode id=2269 questionId=1430 slug=find-the-k-beauty-of-a-number lang=cpp site=leetcode.com title="Find the K-Beauty of a Number"
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;
        for (int i = 0; i + k <= (int)s.size(); i++) {
            int val = stoi(s.substr(i, k));
            if (val != 0 && num % val == 0) count++;
        }
        return count;
    }
};
