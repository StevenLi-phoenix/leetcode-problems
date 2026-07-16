// @leetcode id=2182 questionId=2300 slug=construct-string-with-repeat-limit lang=cpp site=leetcode.com title="Construct String With Repeat Limit"
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        string result;
        int cur = 25;
        while (cur >= 0) {
            if (count[cur] == 0) { cur--; continue; }

            int take = min(count[cur], repeatLimit);
            result.append(take, 'a' + cur);
            count[cur] -= take;

            if (count[cur] > 0) {
                int next = cur - 1;
                while (next >= 0 && count[next] == 0) next--;
                if (next < 0) break;
                result.push_back('a' + next);
                count[next]--;
            } else {
                cur--;
            }
        }
        return result;
    }
};
