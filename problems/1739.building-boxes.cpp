// @leetcode id=1739 questionId=1861 slug=building-boxes lang=cpp site=leetcode.com title="Building Boxes"
class Solution {
public:
    int minimumBoxes(int n) {
        long long k = 0;
        while ((k + 1) * (k + 2) * (k + 3) / 6 <= n) k++;
        long long tetra = k * (k + 1) * (k + 2) / 6;
        long long remaining1 = n - tetra;
        long long base = k * (k + 1) / 2;

        long long m = 0;
        while ((m + 1) * (m + 2) / 2 <= remaining1) m++;
        long long tri = m * (m + 1) / 2;
        long long remaining2 = remaining1 - tri;

        long long answer = base + m + (remaining2 > 0 ? 1 : 0);
        return (int)answer;
    }
};
