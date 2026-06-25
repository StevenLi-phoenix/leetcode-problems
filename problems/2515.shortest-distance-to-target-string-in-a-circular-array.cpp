// @leetcode id=2515 questionId=2598 slug=shortest-distance-to-target-string-in-a-circular-array lang=cpp site=leetcode.com title="Shortest Distance to Target String in a Circular Array"
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = min(abs(i - startIndex), n - abs(i - startIndex));
                res = min(res, dist);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
