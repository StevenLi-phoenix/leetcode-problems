// @leetcode id=3014 questionId=3275 slug=minimum-number-of-pushes-to-type-word-i lang=cpp site=leetcode.com title="Minimum Number of Pushes to Type Word I"
class Solution {
public:
    int minimumPushes(string word) {
        // All letters are distinct, so just distribute them evenly across
        // the 8 keys: the first 8 letters cost 1 push each, the next 8 cost
        // 2 each, and so on.
        int n = word.size();
        int total = 0;
        for (int i = 0; i < n; i++) total += i / 8 + 1;
        return total;
    }
};
