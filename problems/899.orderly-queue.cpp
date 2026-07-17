// @leetcode id=899 questionId=935 slug=orderly-queue lang=cpp site=leetcode.com title="Orderly Queue"
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string best = s;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated < best) best = rotated;
        }
        return best;
    }
};
