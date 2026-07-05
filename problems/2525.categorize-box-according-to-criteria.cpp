// @leetcode id=2525 questionId=2619 slug=categorize-box-according-to-criteria lang=cpp site=leetcode.com title="Categorize Box According to Criteria"
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = (long long)length * width * height;
        bool bulky = length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000LL;
        bool heavy = mass >= 100;

        if (bulky && heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";
        return "Neither";
    }
};
