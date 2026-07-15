// @leetcode id=2516 questionId=2599 slug=take-k-of-each-character-from-left-and-right lang=cpp site=leetcode.com title="Take K of Each Character From Left and Right"
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int total[3] = {0, 0, 0};
        for (char c : s) total[c - 'a']++;
        if (total[0] < k || total[1] < k || total[2] < k) return -1;

        int count[3] = {0, 0, 0};
        int left = 0, best = 0;
        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;
            while (total[0] - count[0] < k || total[1] - count[1] < k || total[2] - count[2] < k) {
                count[s[left] - 'a']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return n - best;
    }
};
