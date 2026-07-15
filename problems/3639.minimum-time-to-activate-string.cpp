// @leetcode id=3639 questionId=3944 slug=minimum-time-to-activate-string lang=cpp site=leetcode.com title="Minimum Time to Activate String"
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long long total = (long long)n * (n + 1) / 2;
        long long invalid = total;

        set<int> stars;
        stars.insert(-1);
        stars.insert(n);

        auto runContribution = [](long long L) { return L * (L + 1) / 2; };

        for (int t = 0; t < n; t++) {
            int i = order[t];
            auto it = stars.lower_bound(i);
            int right = *it;
            --it;
            int left = *it;

            long long L = right - left - 1;
            long long leftPart = i - left - 1;
            long long rightPart = right - i - 1;

            invalid -= runContribution(L);
            invalid += runContribution(leftPart) + runContribution(rightPart);

            stars.insert(i);

            long long valid = total - invalid;
            if (valid >= k) return t;
        }
        return -1;
    }
};
