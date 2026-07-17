// @leetcode id=1521 questionId=1645 slug=find-a-value-of-a-mysterious-function-closest-to-target lang=cpp site=leetcode.com title="Find a Value of a Mysterious Function Closest to Target"
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int best = INT_MAX;
        vector<int> prev;

        for (int x : arr) {
            vector<int> cur;
            cur.push_back(x);
            for (int p : prev) cur.push_back(p & x);

            sort(cur.begin(), cur.end());
            cur.erase(unique(cur.begin(), cur.end()), cur.end());

            for (int v : cur) best = min(best, abs(v - target));

            prev = cur;
        }

        return best;
    }
};
