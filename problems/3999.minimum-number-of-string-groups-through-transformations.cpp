// @leetcode id=3999 questionId=3895 slug=minimum-number-of-string-groups-through-transformations lang=cpp site=leetcode.com title="Minimum Number of String Groups Through Transformations"
class Solution {
public:
    // Booth's algorithm: returns the starting index of the lexicographically
    // smallest rotation of s.
    int leastRotation(const string& s) {
        string ss = s + s;
        int n = ss.size();
        vector<int> f(n, -1);
        int k = 0;
        for (int j = 1; j < n; j++) {
            char sj = ss[j];
            int i = f[j - k - 1];
            while (i != -1 && sj != ss[k + i + 1]) {
                if (sj < ss[k + i + 1]) k = j - i - 1;
                i = f[i];
            }
            if (sj != ss[k + i + 1]) {
                if (sj < ss[k]) k = j;
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }
        return k;
    }

    string canonicalRotation(const string& s) {
        if (s.empty()) return s;
        int k = leastRotation(s);
        string doubled = s + s;
        return doubled.substr(k, s.size());
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string> groups;

        for (const string& w : words) {
            string E, O;
            for (int i = 0; i < (int)w.size(); i++) {
                if (i % 2 == 0) E += w[i];
                else O += w[i];
            }
            string key = canonicalRotation(E) + "#" + canonicalRotation(O);
            groups.insert(key);
        }

        return groups.size();
    }
};
