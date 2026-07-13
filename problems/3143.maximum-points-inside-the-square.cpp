// @leetcode id=3143 questionId=3419 slug=maximum-points-inside-the-square lang=cpp site=leetcode.com title="Maximum Points Inside the Square"
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        vector<pair<long long,char>> arr(n);
        for (int i = 0; i < n; i++) {
            long long d = max(abs((long long)points[i][0]), abs((long long)points[i][1]));
            arr[i] = {d, s[i]};
        }
        sort(arr.begin(), arr.end());

        // A square of a given half-side includes ALL points within that
        // distance, so we grow the square one distinct distance-group at a
        // time; stop at the first group that introduces a duplicate tag
        // (either within the group or against already-included points).
        unordered_set<char> seen;
        int count = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && arr[j].first == arr[i].first) j++;

            unordered_set<char> localSeen;
            bool ok = true;
            for (int k = i; k < j; k++) {
                char c = arr[k].second;
                if (seen.count(c) || localSeen.count(c)) { ok = false; break; }
                localSeen.insert(c);
            }
            if (!ok) break;

            for (int k = i; k < j; k++) seen.insert(arr[k].second);
            count += j - i;
            i = j;
        }
        return count;
    }
};
