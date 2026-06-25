// @leetcode id=657 questionId=657 slug=robot-return-to-origin lang=cpp site=leetcode.com title="Robot Return to Origin"
class Solution {
    public:
    bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
    if (c == 'R') x++;
    else if (c == 'L') x--;
    else if (c == 'U') y++;
    else if (c == 'D') y--;
    }
    return x == 0 && y == 0;
    }
    };
