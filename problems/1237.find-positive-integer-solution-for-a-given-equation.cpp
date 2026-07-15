// @leetcode id=1237 questionId=1358 slug=find-positive-integer-solution-for-a-given-equation lang=cpp site=leetcode.com title="Find Positive Integer Solution for a Given Equation"
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int x = 1, y = 1000;
        while (x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y);
            if (val == z) {
                result.push_back({x, y});
                x++;
                y--;
            } else if (val < z) {
                x++;
            } else {
                y--;
            }
        }
        return result;
    }
};
