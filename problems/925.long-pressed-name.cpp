// @leetcode id=925 questionId=961 slug=long-pressed-name lang=cpp site=leetcode.com title="Long Pressed Name"
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, n = name.size(), m = typed.size();
        while (i < n && j < m) {
            if (name[i] != typed[j]) return false;
            char c = name[i];
            int cntName = 0, cntTyped = 0;
            while (i < n && name[i] == c) { i++; cntName++; }
            while (j < m && typed[j] == c) { j++; cntTyped++; }
            if (cntTyped < cntName) return false;
        }
        return i == n && j == m;
    }
};
