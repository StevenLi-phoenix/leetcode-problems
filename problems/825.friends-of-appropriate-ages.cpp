// @leetcode id=825 questionId=852 slug=friends-of-appropriate-ages lang=cpp site=leetcode.com title="Friends Of Appropriate Ages"
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count[121] = {0};
        for (int a : ages) count[a]++;

        long long total = 0;
        for (int x = 1; x <= 120; x++) {
            if (count[x] == 0) continue;
            for (int y = 1; y <= 120; y++) {
                if (count[y] == 0) continue;
                if (y <= 0.5 * x + 7) continue;
                if (y > x) continue;
                if (y > 100 && x < 100) continue;
                long long requests = (long long)count[x] * count[y];
                if (x == y) requests -= count[x];
                total += requests;
            }
        }
        return (int)total;
    }
};
