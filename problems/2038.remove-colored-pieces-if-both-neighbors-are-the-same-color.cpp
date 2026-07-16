// @leetcode id=2038 questionId=2149 slug=remove-colored-pieces-if-both-neighbors-are-the-same-color lang=cpp site=leetcode.com title="Remove Colored Pieces if Both Neighbors are the Same Color"
class Solution {
public:
    bool winnerOfGame(string colors) {
        long long movesA = 0, movesB = 0;
        int n = colors.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && colors[j] == colors[i]) j++;
            int len = j - i;
            if (len >= 3) {
                if (colors[i] == 'A') movesA += len - 2;
                else movesB += len - 2;
            }
            i = j;
        }
        return movesA > movesB;
    }
};
