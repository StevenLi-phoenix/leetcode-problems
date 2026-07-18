// @leetcode id=3307 questionId=3601 slug=find-the-k-th-character-in-string-game-ii lang=cpp site=leetcode.com title="Find the K-th Character in String Game II"
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long idx = k - 1;
        long long shifts = 0;
        int n = operations.size();
        for (int i = n - 1; i >= 0; i--) {
            long long lenBefore = (i >= 63) ? LLONG_MAX : (1LL << i);
            if (idx >= lenBefore) {
                idx -= lenBefore;
                if (operations[i] == 1) shifts++;
            }
        }
        return 'a' + (shifts % 26);
    }
};
