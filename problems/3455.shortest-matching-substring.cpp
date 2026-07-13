// @leetcode id=3455 questionId=3692 slug=shortest-matching-substring lang=cpp site=leetcode.com title="Shortest Matching Substring"
class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
        // Split p on its two '*' into p1,p2,p3. A matching substring is
        // p1 (as a prefix at position i), then somewhere later an
        // occurrence of p2, then somewhere later still an occurrence of
        // p3. For each valid p1 start, greedily take the EARLIEST possible
        // p2 occurrence and then the earliest possible p3 occurrence after
        // it — taking anything later can only make the substring longer.
        int n = s.size();
        int star1 = p.find('*');
        int star2 = p.find('*', star1 + 1);
        string p1 = p.substr(0, star1);
        string p2 = p.substr(star1 + 1, star2 - star1 - 1);
        string p3 = p.substr(star2 + 1);

        auto findMatches = [&](const string& pat) {
            vector<bool> match(n + 1, false);
            int L = pat.size();
            if (L == 0) {
                fill(match.begin(), match.end(), true);
                return match;
            }
            vector<int> fail(L, 0);
            for (int i = 1; i < L; i++) {
                int j = fail[i - 1];
                while (j > 0 && pat[i] != pat[j]) j = fail[j - 1];
                if (pat[i] == pat[j]) j++;
                fail[i] = j;
            }
            int j = 0;
            for (int i = 0; i < n; i++) {
                while (j > 0 && s[i] != pat[j]) j = fail[j - 1];
                if (s[i] == pat[j]) j++;
                if (j == L) {
                    match[i - L + 1] = true;
                    j = fail[j - 1];
                }
            }
            return match;
        };

        auto nextOcc = [&](const vector<bool>& match) {
            vector<int> nxt(n + 2, n + 1); // n+1 = INF sentinel
            nxt[n] = match[n] ? n : n + 1;
            for (int x = n - 1; x >= 0; x--) nxt[x] = match[x] ? x : nxt[x + 1];
            return nxt;
        };

        vector<bool> match1 = findMatches(p1);
        vector<bool> match2 = findMatches(p2);
        vector<bool> match3 = findMatches(p3);
        vector<int> nxt2 = nextOcc(match2);
        vector<int> nxt3 = nextOcc(match3);

        int L1 = p1.size(), L2 = p2.size(), L3 = p3.size();
        int best = INT_MAX;
        const int INF = n + 1;
        for (int i = 0; i <= n; i++) {
            if (!match1[i] || i + L1 > n) continue;
            int start2 = i + L1;
            int p2start = nxt2[start2];
            if (p2start >= INF) continue;
            int p2end = p2start + L2;
            if (p2end > n) continue;
            int p3start = nxt3[p2end];
            if (p3start >= INF) continue;
            int totalLen = p3start + L3 - i;
            best = min(best, totalLen);
        }
        return best == INT_MAX ? -1 : best;
    }
};
