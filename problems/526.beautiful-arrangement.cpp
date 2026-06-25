// @leetcode id=526 questionId=526 slug=beautiful-arrangement lang=cpp site=leetcode.com title="Beautiful Arrangement"
class Solution {
public:
    int count = 0;
    
    void backtrack(int pos, int n, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }
        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % pos == 0 || pos % num == 0)) {
                used[num] = true;
                backtrack(pos + 1, n, used);
                used[num] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        count = 0;
        vector<bool> used(n + 1, false);
        backtrack(1, n, used);
        return count;
    }
};
