// @leetcode id=3222 questionId=3511 slug=find-the-winning-player-in-coin-game lang=cpp site=leetcode.com title="Find the Winning Player in Coin Game"
class Solution {
public:
    string winningPlayer(int x, int y) {
        int moves = min(x, y / 4);
        return (moves % 2 == 1) ? "Alice" : "Bob";
    }
};
