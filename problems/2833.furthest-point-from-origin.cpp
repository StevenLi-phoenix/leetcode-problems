// @leetcode id=2833 questionId=3019 slug=furthest-point-from-origin lang=cpp site=leetcode.com title="Furthest Point From Origin"
class Solution {
    public:
    int furthestDistanceFromOrigin(string moves) {
    int l = 0, r = 0, u = 0;
    for (char c : moves) {
    if (c == 'L') l++;
    else if (c == 'R') r++;
    else u++;
    }
    return abs(l - r) + u;
    }
    };
