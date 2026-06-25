// @leetcode id=3360 questionId=3625 slug=stone-removal-game lang=cpp site=leetcode.com title="Stone Removal Game"
class Solution {
public:
    bool canAliceWin(int n) {
        // Alice takes 10, Bob takes 9, Alice takes 8, Bob takes 7, ...
        // Sequence of removes: 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
        int remove = 10;
        while (n >= remove) {
            n -= remove;
            remove--;
        }
        // If remove is odd (9, 7, 5,...) it's Bob's turn who couldn't move -> Alice wins
        // If remove is even (10, 8, 6,...) it's Alice's turn who couldn't move -> Bob wins
        // The player who can't move loses
        // When we exit the loop, 'remove' is the amount that couldn't be removed
        // If Alice would have to remove 'remove' but n < remove, Alice loses (even index = Alice's turn when remove is 10, 8, 6...)
        // Alice starts with remove=10 (round 1), Bob with 9 (round 2), Alice with 8, Bob with 7...
        // Alice's turns: remove = 10, 8, 6, 4, 2 (even)
        // Bob's turns: remove = 9, 7, 5, 3, 1 (odd)
        // If remove is even when we can't move: it's Alice who can't -> Bob wins -> return false
        // If remove is odd: it's Bob who can't -> Alice wins -> return true
        return remove % 2 == 1;
    }
};
