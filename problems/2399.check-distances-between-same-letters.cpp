// @leetcode id=2399 questionId=2476 slug=check-distances-between-same-letters lang=cpp site=leetcode.com title="Check Distances Between Same Letters"
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int firstIdx[26];
        fill(begin(firstIdx), end(firstIdx), -1);

        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (firstIdx[c] == -1) {
                firstIdx[c] = i;
            } else {
                if (i - firstIdx[c] - 1 != distance[c]) return false;
            }
        }
        return true;
    }
};
