// @leetcode id=2682 questionId=2791 slug=find-the-losers-of-the-circular-game lang=cpp site=leetcode.com title="Find the Losers of the Circular Game"
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> received(n, false);
        int cur = 0;
        int step = 1;
        while (!received[cur]) {
            received[cur] = true;
            cur = (cur + step * k) % n;
            step++;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) if (!received[i]) result.push_back(i + 1);
        return result;
    }
};
