// @leetcode id=3184 questionId=3421 slug=count-pairs-that-form-a-complete-day-i lang=cpp site=leetcode.com title="Count Pairs That Form a Complete Day I"
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int h : hours) {
            int r = h % 24;
            int need = (24 - r) % 24;
            if (count.count(need)) ans += count[need];
            count[r]++;
        }
        return ans;
    }
};
