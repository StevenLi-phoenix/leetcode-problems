// @leetcode id=1898 questionId=2027 slug=maximum-number-of-removable-characters lang=cpp site=leetcode.com title="Maximum Number of Removable Characters"
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo = 0, hi = (int)removable.size();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (isSubsequence(s, p, removable, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

private:
    bool isSubsequence(const string& s, const string& p, const vector<int>& removable, int k) {
        vector<bool> removed(s.size(), false);
        for (int i = 0; i < k; ++i) removed[removable[i]] = true;

        int j = 0;
        for (int i = 0; i < (int)s.size() && j < (int)p.size(); ++i) {
            if (!removed[i] && s[i] == p[j]) ++j;
        }
        return j == (int)p.size();
    }
};
