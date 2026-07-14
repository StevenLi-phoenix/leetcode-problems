// @leetcode id=2231 questionId=2327 slug=largest-number-after-digit-swaps-by-parity lang=cpp site=leetcode.com title="Largest Number After Digit Swaps by Parity"
class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> odds, evens;
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) evens.push_back(d);
            else odds.push_back(d);
        }
        sort(odds.rbegin(), odds.rend());
        sort(evens.rbegin(), evens.rend());

        int oi = 0, ei = 0;
        for (char& c : s) {
            int d = c - '0';
            if (d % 2 == 0) c = '0' + evens[ei++];
            else c = '0' + odds[oi++];
        }
        return stoi(s);
    }
};
