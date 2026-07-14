// @leetcode id=2982 questionId=3266 slug=find-longest-special-substring-that-occurs-thrice-ii lang=cpp site=leetcode.com title="Find Longest Special Substring That Occurs Thrice II"
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> runs(26);

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runs[s[i] - 'a'].push_back(j - i);
            i = j;
        }

        int ans = -1;
        for (int c = 0; c < 26; c++) {
            auto& r = runs[c];
            if (r.empty()) continue;
            sort(r.rbegin(), r.rend());
            long long a = r[0];
            long long b = r.size() > 1 ? r[1] : 0;
            long long cc = r.size() > 2 ? r[2] : 0;

            long long cand1 = a - 2;
            long long cand2 = min(a - 1, b);
            long long cand3 = cc;

            long long best = max({cand1, cand2, cand3});
            if (best > 0) ans = max(ans, (int)best);
        }
        return ans;
    }
};
