// @leetcode id=2244 questionId=2362 slug=minimum-rounds-to-complete-all-tasks lang=cpp site=leetcode.com title="Minimum Rounds to Complete All Tasks"
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for (int t : tasks) freq[t]++;
        long long rounds = 0;
        for (auto& [val, cnt] : freq) {
            if (cnt == 1) return -1;
            rounds += (cnt + 2) / 3;
        }
        return (int)rounds;
    }
};
