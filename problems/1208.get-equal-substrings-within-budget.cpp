// @leetcode id=1208 questionId=1321 slug=get-equal-substrings-within-budget lang=cpp site=leetcode.com title="Get Equal Substrings Within Budget"
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int left = 0, cost = 0, best = 0;
        for (int right = 0; right < n; right++) {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
