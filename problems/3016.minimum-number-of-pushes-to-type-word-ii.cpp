// @leetcode id=3016 questionId=3276 slug=minimum-number-of-pushes-to-type-word-ii lang=cpp site=leetcode.com title="Minimum Number of Pushes to Type Word II"
class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {};
        for (char c : word) freq[c - 'a']++;
        sort(freq, freq + 26, greater<int>());

        int total = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++)
            total += freq[i] * (i / 8 + 1);
        return total;
    }
};
