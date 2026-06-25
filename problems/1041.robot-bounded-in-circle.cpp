// @leetcode id=1041 questionId=1119 slug=robot-bounded-in-circle lang=cpp site=leetcode.com title="Robot Bounded In Circle"
class Solution {
public:
    bool isRobotBounded(string instructions) {
        // Directions: 0=North, 1=East, 2=South, 3=West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int x = 0, y = 0, dir = 0; // North
        
        for (char c : instructions) {
            if (c == 'G') {
                x += dx[dir];
                y += dy[dir];
            } else if (c == 'L') {
                dir = (dir + 3) % 4;
            } else { // R
                dir = (dir + 1) % 4;
            }
        }
        
        // Bounded if back at origin OR not facing North
        return (x == 0 && y == 0) || dir != 0;
    }
};
