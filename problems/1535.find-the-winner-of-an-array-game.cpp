// @leetcode id=1535 questionId=1657 slug=find-the-winner-of-an-array-game lang=cpp site=leetcode.com title="Find the Winner of an Array Game"
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // The running maximum always ends up at the front, so it beats
        // every element it hasn't already beaten; track its consecutive
        // win streak instead of actually rotating the array.
        int n = arr.size();
        int cur = arr[0], wins = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > cur) {
                cur = arr[i];
                wins = 1;
            } else {
                wins++;
            }
            if (wins >= k) return cur;
        }
        return cur;
    }
};
