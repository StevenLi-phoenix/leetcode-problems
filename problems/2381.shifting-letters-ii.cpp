// @leetcode id=2381 questionId=2465 slug=shifting-letters-ii lang=cpp site=leetcode.com title="Shifting Letters II"
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for (auto& sh : shifts) {
            int delta = sh[2] == 1 ? 1 : -1;
            diff[sh[0]] += delta;
            diff[sh[1] + 1] -= delta;
        }

        string result = s;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            int shift = ((cur % 26) + 26) % 26;
            result[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return result;
    }
};
