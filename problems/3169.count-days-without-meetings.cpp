// @leetcode id=3169 questionId=3430 slug=count-days-without-meetings lang=cpp site=leetcode.com title="Count Days Without Meetings"
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        long long covered = 0;
        long long curStart = -1, curEnd = -1;
        for (auto& m : meetings) {
            int s = m[0], e = m[1];
            if (s > curEnd) {
                if (curEnd != -1) covered += curEnd - curStart + 1;
                curStart = s;
                curEnd = e;
            } else {
                curEnd = max(curEnd, (long long)e);
            }
        }
        if (curEnd != -1) covered += curEnd - curStart + 1;
        return (int)(days - covered);
    }
};
