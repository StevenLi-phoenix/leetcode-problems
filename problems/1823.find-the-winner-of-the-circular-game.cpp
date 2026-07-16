// @leetcode id=1823 questionId=1951 slug=find-the-winner-of-the-circular-game lang=cpp site=leetcode.com title="Find the Winner of the Circular Game"
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};
