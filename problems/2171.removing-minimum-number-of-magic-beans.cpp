// @leetcode id=2171 questionId=2290 slug=removing-minimum-number-of-magic-beans lang=cpp site=leetcode.com title="Removing Minimum Number of Magic Beans"
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        // The optimal target value is always some beans[i] (making all
        // smaller bags empty and trimming larger ones down to beans[i]);
        // maximize what's kept = beans[i] * (n - i) over sorted beans.
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long total = 0;
        for (int v : beans) total += v;

        long long maxKept = 0;
        for (int i = 0; i < n; i++) {
            long long kept = (long long)beans[i] * (n - i);
            maxKept = max(maxKept, kept);
        }
        return total - maxKept;
    }
};
