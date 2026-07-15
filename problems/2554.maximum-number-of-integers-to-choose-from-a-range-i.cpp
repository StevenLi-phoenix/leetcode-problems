// @leetcode id=2554 questionId=2640 slug=maximum-number-of-integers-to-choose-from-a-range-i lang=cpp site=leetcode.com title="Maximum Number of Integers to Choose From a Range I"
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;
        for (int v = 1; v <= n; v++) {
            if (bannedSet.count(v)) continue;
            if (sum + v > maxSum) break;
            sum += v;
            count++;
        }
        return count;
    }
};
