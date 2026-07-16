// @leetcode id=970 questionId=1010 slug=powerful-integers lang=cpp site=leetcode.com title="Powerful Integers"
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> results;
        for (long long xi = 1; xi < bound; xi *= x) {
            for (long long yj = 1; yj < bound; yj *= y) {
                long long sum = xi + yj;
                if (sum <= bound) results.insert((int)sum);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(results.begin(), results.end());
    }
};
