// @leetcode id=3001 questionId=3270 slug=minimum-moves-to-capture-the-queen lang=cpp site=leetcode.com title="Minimum Moves to Capture The Queen"
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Rook capture: same row or column as the queen, not blocked by the bishop.
        if (a == e) {
            bool blocked = (c == a) && (d > min(b, f)) && (d < max(b, f));
            if (!blocked) return 1;
        }
        if (b == f) {
            bool blocked = (d == b) && (c > min(a, e)) && (c < max(a, e));
            if (!blocked) return 1;
        }

        // Bishop capture: same diagonal as the queen, not blocked by the rook.
        if (abs(c - e) == abs(d - f)) {
            bool blocked = false;
            if (abs(a - c) == abs(b - d) && (a - c) * (f - d) == (b - d) * (e - c)) {
                int stepX = (e > c) ? 1 : -1;
                int stepY = (f > d) ? 1 : -1;
                int x = c + stepX, y = d + stepY;
                while (x != e) {
                    if (x == a && y == b) { blocked = true; break; }
                    x += stepX; y += stepY;
                }
            }
            if (!blocked) return 1;
        }

        return 2;
    }
};
