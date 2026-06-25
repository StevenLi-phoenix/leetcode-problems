// @leetcode id=3006 questionId=3245 slug=find-beautiful-indices-in-the-given-array-i lang=cpp site=leetcode.com title="Find Beautiful Indices in the Given Array I"
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        auto kmpSearch = [](const string& text, const string& pat) {
            vector<int> result;
            int n = text.size(), m = pat.size();
            vector<int> lps(m, 0);
            // Build LPS array
            for (int i = 1, len = 0; i < m;) {
                if (pat[i] == pat[len]) { lps[i++] = ++len; }
                else if (len) { len = lps[len-1]; }
                else { lps[i++] = 0; }
            }
            // Search
            for (int i = 0, j = 0; i < n;) {
                if (text[i] == pat[j]) { i++; j++; }
                if (j == m) { result.push_back(i - j); j = lps[j-1]; }
                else if (i < n && text[i] != pat[j]) {
                    if (j) j = lps[j-1]; else i++;
                }
            }
            return result;
        };
        
        vector<int> posA = kmpSearch(s, a);
        vector<int> posB = kmpSearch(s, b);
        vector<int> result;
        
        for (int i : posA) {
            // Binary search in posB for any j with |j - i| <= k
            auto lo = lower_bound(posB.begin(), posB.end(), i - k);
            if (lo != posB.end() && *lo <= i + k) {
                result.push_back(i);
            }
        }
        return result;
    }
};
