// @leetcode id=849 questionId=879 slug=maximize-distance-to-closest-person lang=cpp site=leetcode.com title="Maximize Distance to Closest Person"
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int best = 0;
        int prev = -1;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prev == -1) {
                    best = max(best, i);
                } else {
                    best = max(best, (i - prev) / 2);
                }
                prev = i;
            }
        }
        best = max(best, n - 1 - prev);
        return best;
    }
};
