// @leetcode id=1552 questionId=1675 slug=magnetic-force-between-two-balls lang=cpp site=leetcode.com title="Magnetic Force Between Two Balls"
class Solution {
public:
    bool canPlace(vector<int>& position, int m, int minForce) {
        int count = 1;
        int last = position[0];
        for (int i = 1; i < (int)position.size(); i++) {
            if (position[i] - last >= minForce) {
                count++;
                last = position[i];
            }
        }
        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int lo = 1, hi = position[n - 1] - position[0];
        int best = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(position, m, mid)) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }
};
