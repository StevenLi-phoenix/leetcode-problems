// @leetcode id=1104 questionId=1194 slug=path-in-zigzag-labelled-binary-tree lang=cpp site=leetcode.com title="Path In Zigzag Labelled Binary Tree"
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;

        while (label >= 1) {
            path.push_back(label);
            if (label == 1) break;

            int row = 32 - __builtin_clz(label);
            int rowStart = 1 << (row - 1);
            int posInRow = (row % 2 == 1)
                ? label - rowStart
                : ((1 << row) - 1 - label);

            int parentPosInRow = posInRow / 2;
            int parentRow = row - 1;
            int parentRowStart = 1 << (parentRow - 1);
            label = (parentRow % 2 == 1)
                ? parentRowStart + parentPosInRow
                : ((1 << parentRow) - 1 - parentPosInRow);
        }

        reverse(path.begin(), path.end());
        return path;
    }
};
