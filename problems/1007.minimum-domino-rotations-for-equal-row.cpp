// @leetcode id=1007 questionId=1049 slug=minimum-domino-rotations-for-equal-row lang=cpp site=leetcode.com title="Minimum Domino Rotations For Equal Row"
class Solution {
public:
    int tryValue(vector<int>& tops, vector<int>& bottoms, int val) {
        int rotateTop = 0, rotateBottom = 0;
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val) return -1;
            if (tops[i] != val) rotateTop++;
            else if (bottoms[i] != val) rotateBottom++;
        }
        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = tryValue(tops, bottoms, tops[0]);
        if (result != -1) return result;
        return tryValue(tops, bottoms, bottoms[0]);
    }
};
