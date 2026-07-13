// @leetcode id=670 questionId=670 slug=maximum-swap lang=cpp site=leetcode.com title="Maximum Swap"
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int lastOccurrence[10];
        fill(lastOccurrence, lastOccurrence + 10, -1);
        for (int i = 0; i < n; i++) lastOccurrence[s[i] - '0'] = i;

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (lastOccurrence[d] > i) {
                    swap(s[i], s[lastOccurrence[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
