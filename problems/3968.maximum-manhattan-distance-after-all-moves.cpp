// @leetcode id=3968 questionId=4340 slug=maximum-manhattan-distance-after-all-moves lang=cpp site=leetcode.com title="Maximum Manhattan Distance After All Moves"
class Solution {
public:
    int maxDistance(string moves) {
        int netX = 0, netY = 0, free = 0;
        for (char c : moves) {
            if (c == 'U') netY++;
            else if (c == 'D') netY--;
            else if (c == 'L') netX--;
            else if (c == 'R') netX++;
            else free++;
        }
        return abs(netX) + abs(netY) + free;
    }
};
