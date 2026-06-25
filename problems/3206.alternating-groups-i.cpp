// @leetcode id=3206 questionId=3463 slug=alternating-groups-i lang=cpp site=leetcode.com title="Alternating Groups I"
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int prev = colors[(i - 1 + n) % n];
            int next = colors[(i + 1) % n];
            if (colors[i] != prev && colors[i] != next) count++;
        }
        return count;
    }
};
