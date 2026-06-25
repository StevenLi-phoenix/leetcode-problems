// @leetcode id=2126 questionId=2245 slug=destroying-asteroids lang=cpp site=leetcode.com title="Destroying Asteroids"
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (int a : asteroids) {
            if (m < a) return false;
            m += a;
        }
        return true;
    }
};
