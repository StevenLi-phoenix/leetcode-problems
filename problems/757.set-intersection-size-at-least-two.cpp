// @leetcode id=757 questionId=759 slug=set-intersection-size-at-least-two lang=cpp site=leetcode.com title="Set Intersection Size At Least Two"
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });

        long long p1 = LLONG_MIN, p2 = LLONG_MIN;
        int count = 0;

        for (auto& iv : intervals) {
            int s = iv[0], e = iv[1];
            if (s > p2) {
                p1 = e - 1;
                p2 = e;
                count += 2;
            } else if (s > p1) {
                p1 = p2;
                p2 = e;
                count += 1;
            }
        }
        return count;
    }
};
