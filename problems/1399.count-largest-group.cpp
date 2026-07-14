// @leetcode id=1399 questionId=1500 slug=count-largest-group lang=cpp site=leetcode.com title="Count Largest Group"
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> count;
        int maxSize = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0, t = i;
            while (t > 0) { sum += t % 10; t /= 10; }
            maxSize = max(maxSize, ++count[sum]);
        }

        int groups = 0;
        for (auto& [k, v] : count) if (v == maxSize) groups++;
        return groups;
    }
};
