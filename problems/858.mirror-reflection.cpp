// @leetcode id=858 questionId=888 slug=mirror-reflection lang=cpp site=leetcode.com title="Mirror Reflection"
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g;
        q /= g;

        bool pEven = (p % 2 == 0);
        bool qEven = (q % 2 == 0);

        if (!pEven && !qEven) return 1;
        if (!pEven && qEven) return 0;
        return 2;
    }

private:
    int gcd(int a, int b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }
};
