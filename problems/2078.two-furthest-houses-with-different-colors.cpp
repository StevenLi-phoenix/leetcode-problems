// @leetcode id=2078 questionId=2199 slug=two-furthest-houses-with-different-colors lang=cpp site=leetcode.com title="Two Furthest Houses With Different Colors"
class Solution {
    public:
    int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
    if (colors[i] != colors[j]) {
    res = max(res, j - i);
    }
    }
    }
    return res;
    }
    };
