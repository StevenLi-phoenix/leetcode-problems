// @leetcode id=3784 questionId=4138 slug=minimum-deletion-cost-to-make-all-characters-equal lang=cpp site=leetcode.com title="Minimum Deletion Cost to Make All Characters Equal"
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        // Keep whichever letter's total cost is highest; delete everything else.
        long long total = 0, byLetter[26] = {};
        for (int i = 0; i < (int)s.size(); i++) {
            total += cost[i];
            byLetter[s[i] - 'a'] += cost[i];
        }
        long long maxKeep = *max_element(byLetter, byLetter + 26);
        return total - maxKeep;
    }
};
